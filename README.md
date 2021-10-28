# ESP-NOW

## O que é:

É protocolo desenvolvido pela própria Espressif, permitindo a comunicação de diversos aparelhos sem a comunicação wi-fi, sendo uma comunicação “chip com chip”. As vantagens é que é uma comunicação segura, rápida, baixo consumo de energia e após o pareamento é persistente ao peer-to-peer.

## Como funciona:

Todos os ESPs estão no modo station, ou seja, não a distinção entre eles, podendo ser qualquer um o que irá “comandar” os demais, ou se preferir, comunicarem entre si sem haver um principal.

Cada ESP é referenciado pelo seu macAddress, dessa forma especificamos para qual ESP queremos passar o sinal. Podemos saber o seu valor com seguinte código: 

![Foto55](https://user-images.githubusercontent.com/77392769/139269288-2250938b-8dd8-47db-a74a-8ede21b7a892.png)

# Mostrando melhor como utilizá-lo, separei alguns códigos que você pode acessar neste repositório

O exemplo se trata de um ESP que está recebendo sinal por uma porta específica e repassando a informação para os outros ESPs.  

### ESPNowMaster.io:

Será o código do ESP que irá receber a informação e repassar para os demais, por isso é tratado como “master” 

### ESPNowSlave.io:

Será o código do ESP que irá receber a informação do master e executar o que foi exigido, por isso é tratado como “Slave(Escravo)” 
