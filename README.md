# UEEmojimonExample
Unreal Client implementation of Emojimon example project using UEMUD Plugin


## Dependencies:

Plugins:

https://github.com/a-najafi/ContextFramework

https://github.com/a-najafi/UEMUD

https://github.com/thejinchao/turbolink

https://github.com/G7DAO/web3.unreal

Notes: 
- check project settings for custom settings regarding mud world settings, jrpc server address, grpc server addresses 
- all plugins are included in repo for convenience
- needs hyper play installed and running to send transaction currently, wip encoding and siging transactions for eth_sendRawTransaction
- sync is using mud grpc services stream, snapshot and they need to be running. set address and port through turbolink plugin settings
- to get drip faucet service needs to be running.
- included turbolink plugin has generated classes for mud services. they will be refactored into UEMUD later
- web3Unreal has been modified to receive chainmetadata in function
- press E to join game (will always join game on 2,2) use wasd or arrow keys to move avatar. local avatar is green. white avatars are other players

