{
    'targets': [
        {
            'target_name': 'object-rest-spread-test',

            'sources': [
                "src/object-rest-spread-test.cpp",
            ],

            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")",
            ],

            'cflags!': [ '-fno-exceptions' ],
            'cflags_cc!': [ '-fno-exceptions' ],
            'conditions': [
                ["OS=='win'", {
                "defines": [
                    "_HAS_EXCEPTIONS=1"
                ],
                "msvs_settings": {
                    "VCCLCompilerTool": {
                    "ExceptionHandling": 1
                    },
                },
                }],
                ["OS=='mac'", {
                    'cflags+': ['-fvisibility=hidden'],

                    'xcode_settings': {
                        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
                        'CLANG_CXX_LIBRARY': 'libc++',
                        'MACOSX_DEPLOYMENT_TARGET': '10.7',
                        'GCC_SYMBOLS_PRIVATE_EXTERN': 'YES', # -fvisibility=hidden
                    },
                }],
            ],

            'dependencies': [
                "<!(node -p \"require('node-addon-api').gyp\")"
            ]
        }
    ]
}
