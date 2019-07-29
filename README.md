# Adafruit-Lora-Feather-Board-for-Solar-Panels-Data-Transmission
The repository consists the source code for Data Transmission from Solar Panels via the RS 485 Converters to the Adafruit Lora Feather Boards

There are two files in this Repository : 
1. Transmitter.ino
2. Receiver (Feather9x_RX.ino)

The transmitter code is uploaded on the LORA feather board which is connected to the RS 485 converter which gets data from the Solar Panels 


The receiver code is uploaded to another Lora Feather Board which has no connection with the RS 485 Converters. It receives the wireless data trasnmitted by the first Lora Feather board which is connected to the RS 485 converters. 

With the above code, you can receive data bit by bit from the RS 485 conveter and in turn transmit it to the Stand by Feather board using the radio head lora library.

On how to use the radio head library and establish a simple connection between two feather boards, please follow this link, it contains step by step procedure to setup a basic communication between two Lora feather boards using the Radio head library and two small antennas which have to be soldered to the board:

1. https://learn.adafruit.com/adafruit-feather-32u4-radio-with-lora-radio-module/using-the-rfm-9x-radio
2. https://www.youtube.com/watch?v=0VnQ9cyaZik
