# ESP-NOW

## O que é:

É protocolo desenvolvido pela própria Espressif, permitindo a comunicação de diversos aparelhos sem a comunicação wi-fi, sendo uma comunicação “chip com chip”. As vantagens é que é uma comunicação segura, rápida, baixo consumo de energia e após o pareamento é persistente ao peer-to-peer.

## Como funciona:

Todos os ESPs estão no modo station, ou seja, não a distinção entre eles, podendo ser qualquer um o que irá “comandar” os demais, ou se preferir, comunicarem entre si sem haver um principal.

Cada ESP é referenciado pelo seu macAddress, ou seja, dessa forma especificamos para qual ESP queremos passar o sinal. Podemos saber o seu valor com seguinte código: 

![Foto55](https://user-images.githubusercontent.com/77392769/139269288-2250938b-8dd8-47db-a74a-8ede21b7a892.png)

# Mostrando melhor como utilizá-lo, separei alguns códigos que você pode acessar neste repositório

O exemplo se trata de um ESP que está funcionando como “master”, ou seja, ele está mandando sinal para os demais ESPs

### Cod 1:


