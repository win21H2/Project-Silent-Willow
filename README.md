<h1 align="center">Project Silent Willow</h1>
<p align="center">
    <img src="https://user-images.githubusercontent.com/92825997/187325584-4cc5d7f3-468a-4426-8c7f-93117b1a4f07.png" width=200/>
    <img src="https://user-images.githubusercontent.com/92825997/187325625-ba71f7d2-1b81-47a8-98ec-602794a38036.png" width=200/>
</p>
<br/>
<br/>

### A description of Project Silent Willow
Project Silent Willow is a mechanum wheel vehicle (meaning it can move in any direction without having to turn). I have been working on it for 2 years by now and will continue working on it through highschool as I develop my programming skills originally started off with just the base of the vehicle only having bare minimum features such as speed and direction control. As mentioned above, it is controlled by a custom application which I made in MIT App Inventor (ai2) and in the future I am planning to completely custom make the application in Android Studio using Kotlin and XML. I then later found out about Jetson nanos and I started integrating them in with for example the LiDAR being the first integration.

Although Project Silent Willow is the vehicle itself, the group of words ```Project Silent Willow``` represents a larger project (which includes this repository, other repositories [such as <a href="https://github.com/win21H2/Project-Silent-Willow-Main-Application">Project-Silent-Willow-Main-Application</a> which can be run on multiple OSes. Currently, I am working on a Windows Desktop version and trying to get a galaxy watch version running], and my <a href="https://324hz.dev">main website</a>) which consists of multiple smaller projects such as the above mentioned and LiDAR scanning.

### Main future steps
 - Create documentation for the hardware side of the project (under `HARDWARE.md`)
 - Work on integrating the LiDAR unit (such as distance detection for vehicle control)
 - Try to integrate image segmentation (with object detection)
 
Image segmentation example<br><br>
![image](https://user-images.githubusercontent.com/92825997/200585969-ea243867-8ffa-4cd4-9251-5ca5d6b9b944.png)
 
### Feedback from Nvidia DLI (Jetson AI specialist certification)
##### AI:  3.5<br>
> Considering if you plan to continue developing the project, I’d encourage you to incorporate additional DNNs like object detection, segmentation, ect for more complex autonomous navigation. Maybe you already plan to do this.

##### Impact: 4<br>
> The work aims to improve the agility of autonomous ground vehicles and hence has many potential impacts in robotics.

##### Reproducibility:  3.5<br>
> The code appears well-written an easy to follow. I didn’t find plans for the physical robot itself, but maybe you have that somewhere?

##### Documentation:  4<br>
> Thorough and well-written documentation of the code!

<br>

### Technology involved
The main pieces of technology used include Arduinos, Nvidia Jetson nanos and a RPLiDAR A1M8 scanner although there are others such as DRV8825 (stepper motor drivers), shift registers, HC-05 BT modules, and stepper motors.
### The functions of Project Silent Willow
Project Silent Willow is intended to be used as a vehicle which can drive in smaller more confined spaces which might be for example hazardous to people and as such, has a camera and a LiDAR unit near the top of the vehicle
### Files in this repository

<a href="https://github.com/win21H2/Project-Silent-Willow/tree/main/main%20code">`/main code`</a><br/>
<a href="https://github.com/win21H2/Project-Silent-Willow/blob/main/main%20code/BTcontrol.ino">`/main code/BTcontrol.ino`</a> => Bluetooth control<br/>
<a href="https://github.com/win21H2/Project-Silent-Willow/blob/main/main%20code/SRcontrol.ino">`/main code/SRcontrol.ino`</a> => Serial control (from Nvidia Jetson nano)

<a href="https://github.com/win21H2/Project-Silent-Willow/tree/main/sample%20code">`/sample code`</a><br/>
<a href="https://github.com/win21H2/Project-Silent-Willow/blob/main/sample%20code/switchcase..ino">`sample code/switchcase.ino`</a> => Testing switch cases (serial and bluetooth control)

<a href="https://github.com/win21H2/Project-Silent-Willow/tree/main/image-recognition">`/image-recognition`</a><br/>
<a href="https://github.com/win21H2/Project-Silent-Willow/blob/main/image-recognition/image-recognition.ipynb">`/image-recognition/image-recognition.ipynb`</a> => The image recognition program Jupyter notebook<br/>
<a href="https://github.com/win21H2/Project-Silent-Willow/tree/main/image-recognition/test%20code">`/image-recognition/test code`</a><br/>
<a href="https://github.com/win21H2/Project-Silent-Willow/blob/main/image-recognition/test%20code/arduinoledtest.ino">`/image-recognition/test code/arduinoledtest.ino`</a> => Serial test with Arduino and some LEDs<br/>
<a href="https://github.com/win21H2/Project-Silent-Willow/blob/main/image-recognition/test%20code/caseswitch.ino">`/image-recognition/test code/caseswitch.ino`</a> => Serial test with Arduino and some LEDs (COPY)<br/>

# Image recognition with Project Silent Willow

>Throughout this section of the repository, you will learn how to setup your Jetson nano to run a Jupyter Labs notebook provided by the Nvidia DLI. You will also learn how to edit the code so that you can make an Arduino respond to data it recieves from the Jetson nano

### Quick access index
><a a href="#prerequisites">1 - Prerequisites</a><br>
><a href="#what-you-need-to-have">2 - What you need to have</a><br>
><a href="#getting-started">3 - Getting started</a><br>
><a href="#making-edits-to-the-program">4 - Making edits to the program</a><br>
><a href="#including-the-arduino-board-without-the-jetson">5 - Including the Arduino board without the Jetson</a><br>
><a href="#including-the-arduino-board-with-the-jetson-using-an-example">6 - Including the Arduino board with the Jetson using an example</a><br>
><a href="#wrap-up">7 - Wrap up</a><br>

[↑ Go to top ↑](#quick-access-index)

# Prerequisites

 > - Basic understanding of the Ubuntu/Linux CLI and how to enter commands/open files and navigate paths as well as sudo, pip, and sh commands <br>
 > - Understanding of how to use the Arduino IDE and how to upload code as well as basic familiarity of C++ and how to write code for Arduino<br>
 > - <u>Languages used include Python and C++</u>

 [↑ Go to top ↑](#quick-access-index)

# What you need to have

> - A Nvidia Jetson Nano board (you can get one [<u>here</u>](https://www.amazon.com/NVIDIA-Jetson-Nano-Developer-945-13541-0000-000/dp/B08J157LHH/ref=sr_1_3?crid=14OGE6DXXIQJV&keywords=nvidia+jetson+nano+2gb&qid=1650155641&sprefix=nvidia+jetson+nano+%2Caps%2C212&sr=8-3) although keep in mind that as of now they might not be in stock) <br>
 > - A USB camera (I used the [<u>Logitech C920x HD Webcam</u>](https://www.amazon.com/Logitech-C920x-Pro-HD-Webcam/dp/B085TFF7M1/ref=sr_1_3?crid=27NQO1U637C2M&keywords=logitech%2Busb%2Bcamera&qid=1650155485&sprefix=logitech%2Busb%2Bcamera%2Caps%2C160&sr=8-3&th=1) for this project although you can use a different USB camera)
 > - A microSD card (you can get one [<u>here</u>](https://www.amazon.com/SanDisk-Ultra-UHS-I-Memory-Adapter/dp/B00M55C0NS/ref=sr_1_6?crid=38NYM8JJMSNRA&keywords=micro%2Bsd%2Bcard&qid=1650155732&sprefix=micro%2Bsd%2Bcard%2Caps%2C255&sr=8-6&th=1) one although I would recommend getting one that is 64gb)
 > - An Arduino Uno (you can get one [<u>here</u>](https://store.arduino.cc/products/arduino-uno-rev3))

 [↑ Go to top ↑](#quick-access-index)

<h1 align="center">Getting Started</h1>

### Setting up the Jetson Nano
>During this stage you will add a SWAP file, setup a docker container for the Jetson nano, and finnaly log into the docker container and open a notebook in Jupyter Labs

Step 1. Run the below command to check how much memory you have on the Jetson
>Description: The image recognition program requires a lot of RAM and using the next few commands, you will make something thats called "virtual RAM" which is as the name suggests, RAM that is stored virtually and tricks the Jetson into thinking it has more RAM compared to what it physically has. <br>

    free -m


Step 2. Run the following commands <u>ONLY</u> if your Jetson does not already have a SWAP file
>Description: The commands below will create the virtual RAM needed for the program to run normally

    sudo systemctl disable nvzramconfig
    sudo fallocate -l 4G /mnt/4GB.swap
    sudo chmod 600 /mnt/4GB.swap
    sudo mkswap /mnt/4GB.swap

    sudo su
    echo "/mnt/4GB.swap swap swap defaults 0 0" >> /etc/fstab
    exit


Step 3. Run the following commands to make the docker container needed to run Jupyter Labs
>Description: The following commands will first make a directory for the docker container, that is followed by the script which is run every time you use the docker command which sets some things up. The last two steps are for making that script executable so that we can use a ./.sh command to run the docker.

    mkdir -p ~/nvdli-data

    echo "sudo docker run --runtime nvidia -it --rm --network host \
    --volume ~/nvdli-data:/nvdli-nano/data \
    --device /dev/video0 \
    nvcr.io/nvidia/dli/dli-nano-ai:v2.0.2-r32.7.1" > docker_dli_run.sh
    
    chmod +x docker_dli_run.sh

    ./docker_dli_run.sh
    
    
Step 4. Log into Jupyter Labs
>Description: You use the URL that was provided after running the docker script above. You have to copy and paste it into a browser and use the default password `dlinano` to login. A picture of the provided URL is below (note the IP shown will <u>NOT</u> be the same for you)

<kbd><img src="https://user-images.githubusercontent.com/92825997/163696048-b2b53b30-eeb3-405a-b0b4-602776c7d8d6.png"/></kbd>

>If you see something like the below image, you have setup your Jetson nano correctly and can head over to the next steps

<kbd><img src="https://user-images.githubusercontent.com/92825997/163696076-2bb063ed-7d28-462a-8a77-121c0170d2a9.png"/></kbd>

[↑ Go to top ↑](#quick-access-index)

# Making edits to the program

>During this stage you will make edits to the notebook so that we can run the custom code. You will also learn how the transmission works on the Jetson side (note that the Arduino side is the next section)

Step 1. Open the notebook and open up the file `classification` >> `classification_interactive.ipynb`
>Description: This file will be the only file that we will be working in and we will only make a few edits to the code although if you want to customize it further, feel free to do so.

Step 2. Add in a `pip` install cell at the very top and it has to contain the below:
>Description: The command below will install the needed library in order to communicate between the Jetson nano and the Arduino

```
!pip3 install pyserial
```

Step 3. Edit the 7th cell with the information that you can find in the ipynb file that is in this repository
>Description: This is where almost all of the edits are made so make sure that you look over the code and make sure that every line is correct. Also try to understand everything instead of just copying and pasting it.

[↑ Go to top ↑](#quick-access-index)

# Including the Arduino board without the Jetson

>During this stage you will find out what the Arduino side of the code looks like, find out what the different lines do, and test out the code in the Serial Monitor (we are not using the Jetson yet because it requires a different baud rate which we have to setup later)

Step 1. Open up the file `image-recognition` >> `test code` >> `caseswitch.ino` and load it to the Arduino IDE
>Description: You should see something that looks like the below code. In short, this code will be the test code we will use to test the serial connection with the Arduino Uno

```c++
void setup() {
  Serial.begin(9600);
  for (int thisPin = 2; thisPin < 4; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    switch (inByte) {
      case 'a':
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
        break;
      case 'b':
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
        break;
      case 'c':
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
        break;
    }
  }
}
```

Step 2. Select the correct COM port and board (in this case the Arduino Uno @ whatever port the Arduino is using and upload the code to the Uno)

### Code walk-through

We first use the void setup section to firstly set up the serial baud rate and the pins for the LEDs
>Description: We use a ```for``` statement to make each LED from pin 2 to pin 3 (since the pin = 2 and is < than 4) an output pin and we use the variable name ```thisPin``` to set the values

```c++
void setup() {
  Serial.begin(9600);
  for (int thisPin = 2; thisPin < 4; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}
```
We then need to check if there is any serial data using the code below
>Description: We use an ```if``` statement to check if the serial line is avaiable (there is no point sending data if the line is taken up by another thing) and if the value is greater than 0 (0 meaning there is nothing inputted) and make a variable based on the serial input
```c++
void loop() {
  if (Serial.available() > 0) {
    int inByte = Serial.read();
```
We then need to use the ```inByte``` variable in a case switch to check the input and if the input is "a" and make an output (in this case turn on certain LEDs)
>Description: We use the variable to check which letter was inputted to the Serial Monitor and then turn the case on for example if we input "a" so that only the code in case "a" is ran until another input is found. NOTE: this is reapeated for case "b" and "c" but the LEDs are different
```c++
    switch (inByte) {
      case 'a':
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
        break;
      case 'b':
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
        break;
      case 'c':
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
        break;
    }
  }
}
```
Once you have uploaded the code to the board, you can see that if you open up the serial monitor and set the baud rate to ```9600``` and start inputting values like "a", you should see the LED on pin 4 light up and vice versa with the other LEDs

# Including the Arduino board with the Jetson using an example
>During this stage you will upload and test the example code with the Jetson nano

Step 1. Open up the file `image-recognition` >> `test code` >> `arduinoledtest.ino` and load it to the Arduino IDE
>Description: You should see something that looks like the below code. In short, this code will be the test code we will use to check if the Jetson is sending the serial commands to the Arduino.

```c++
int rled = 2;
int gled = 3;

void setup() {
  Serial.begin(11520);
  pinMode(rled, OUTPUT);
  pinMode(gled, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    switch (inByte) {
      case 'R':
        digitalWrite(rled, HIGH);
        digitalWrite(gled, LOW);
        break;
      case 'B':
        digitalWrite(rled, LOW);
        digitalWrite(gled, HIGH);
        break;
      case 'O':
        digitalWrite(rled, LOW);
        digitalWrite(gled, LOW);
        break;
    }
  }
}
```
Step 2. Select the correct COM port and board (in this case the Arduino Uno @ whatever port the Arduino is using and upload the code to the Uno

### Code walk-through

This code looks similar to the one before right? That is correct although we have to change up a few things. First, we have to change the baud rate and then we have to change the LEDs we have to better suit the task we are trying to complete
>Description: We use the baud rate of ```11520``` because the Jetson nano is able to communicate using that baud rate. NOTE: this baud rate is NOT the same as the default Arduino IDE baud rate so you will not be able to send serial commands to the Arduino via the serial monitor

Once you have uploaded the code to the Arduino board, you can connect the board to the Jetson using the programming cable and get the image recognition program up and running. What you will notice is that when the Prediction score goes above a certain point, the green LED turns on and vice versa!

[↑ Go to top ↑](#quick-access-index)

# Wrap up

To conclude this project, you should by now understand how to get a docker container running on a Jetson, get Jupyter labs running, know how to run your first image recognition program, and know how to edit the code so that it works with an Arduino Uno. You will also have learnt what to use with serial communications with a Jetson nano to Arduino Uno program written using case switches.

>If you have any questions regarding what is in this repository, contact me via discord @ 324Hz#4539, via twitter @win21H2, or by email @ 1024bitcoins@gmail.com although note that I am not on my email all the time and Discord/Twitter are the better options!

[↑ Go to top ↑](#quick-access-index)
