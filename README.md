# Модуль вычисления crc32IEEE из строки, закодированной в base64.
## install

npm install node-addon-api --save-prod

npm install crc32-base64

## Example
const crc32 = require('crc32-base64')
OR 
import crc32 from 'crc32-base64'

const buff64 = Buffer.from("Привет МИР!!!").toString('base64')

console.log(buff64)

//OUT: 0J/RgNC40LLQtdGCINCc0JjQoCEhIQ==

console.log('crc32IEEE:',crc32.IEEE(buff64))

//OUT: crc32IEEE: 2736488481

