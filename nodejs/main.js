var robot = require("robotjs");

const SerialPort = require('serialport')
const Readline = require('@serialport/parser-readline')
const port = new SerialPort('/dev/ttyUSB0', { baudRate: 38400 })

const parser = new Readline()
port.pipe(parser)

parser.on('data', function(data){

        console.log(data);
        if(data.startsWith('c')){ 
            robot.keyTap('c');
            console.log('bddddddddddddddddddddd');
        }
        if(data.startsWith('b')){ 
            robot.keyTap('b');
            console.log('bddddddddddddddddddddd');
        }


        if(data.startsWith('d')){ 
            robot.keyTap('n');
            console.log('bddddddddddddddddddddd');
        }
})