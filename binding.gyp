{
  "targets": [
    {
      "target_name": "crc32_base64",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "./src/crc32.cpp",
        "./src/base64.cpp",
        "./src/index.cpp",
      ],
      "include_dirs": [
         "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}