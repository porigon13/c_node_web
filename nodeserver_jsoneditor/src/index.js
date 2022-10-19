const express = require('express');
const http = require('http');
const socketIo = require('socket.io');

const app = express();
const server = http.Server(app);
const io = socketIo(server);

const PORT = 3000;

//udp c -> node.js -> web
const dgram_fromC = require('dgram');
const { json } = require('express');
const PORT_A = 12345;
const HOST_A = '127.0.0.1';
const PORT_B = 12346;
const HOST_B = '127.0.0.1';
const socket_udp_from_c_to_nodejs_to_web = dgram_fromC.createSocket('udp4');
socket_udp_from_c_to_nodejs_to_web.bind(PORT_A, HOST_A);//nodejs側bind

//udp web -> node.js -> c
const dgram_fromWeb = require('dgram');
const { emit } = require('process');
const PORT_C = 12347;
const HOST_C = '127.0.0.1';
const PORT_D = 12348;
const HOST_D = '127.0.0.1';
const socket_udp_from_web_to_node_c = dgram_fromWeb.createSocket('udp4');
socket_udp_from_web_to_node_c.bind(PORT_D, HOST_D);//nodejs側bind




// app.get('/dist/jsoneditor.css', (req, res) => {
//   res.sendFile(__dirname + '/dist/jsoneditor.css');
// });

// app.get('/dist/jsoneditor.js', (req, res) => {
//   res.sendFile(__dirname + '/dist/jsoneditor.js');
// });

// app.get('/dist/img/jsoneditor-icons.svg', (req, res) => {
//   res.sendFile(__dirname + '/dist/img/jsoneditor-icons.svg');
// });

app.get('/', (req, res) => {
  res.sendFile(__dirname + '/index.html');
});

//udp c -> node.js -> web
socket_udp_from_c_to_nodejs_to_web.on('message', (message, remote) => {
  console.log('c -> ' + message);//メッセージ型(文字列以外にもデータがある,例えば文字列の大きさとか)付加情報を含んでいるなのでtostringする必要がある
  message_string = message.toString();//文字列だけ取り出す
  io.emit('fromC_receiveMessage', message_string);
});

server.listen(PORT, () => {
  console.log(`listening on port ${PORT}`);
});

io.on('connection', (socket) => {
  console.log('user connected');
  socket.on('post_message', (data) => {
    io.emit("send",data);

    socket_udp_from_web_to_node_c.send(data, 0, data.length, PORT_C, HOST_C, (err, bytes) => {
      if (err) throw err;
    });
  });
});

