<h2 align="center">Project Silent Willow</h2>
<p align="center">
    <img src="https://user-images.githubusercontent.com/92825997/187325584-4cc5d7f3-468a-4426-8c7f-93117b1a4f07.png" width=200/>
    <img src="https://user-images.githubusercontent.com/92825997/187325625-ba71f7d2-1b81-47a8-98ec-602794a38036.png" width=200/>
</p>
<br/>
<br/>

### Description
##### I will store all of Project Silent Willow's code as well as other code used for testing the vehicle in this repository.
<br/>

### Quick access index
<a href="#a-description-of-project-silent-willow">A description of Project Silent Willow?</a><br/>
<a href="">Technology involved</a><br/>
<a href="#the-functions-of-project-silent-willow">The functions of Project Silent Willow</a><br/>
<a href="#files-in-this-repository">Files in this repository</a><br/>
<a href="#other-repositories-used-in-project-silent-willow">Other repositories used in Project Silent Willow</a><br/>

### A description of Project Silent Willow
Project Silent Willow is a mechanum wheel vehicle (meaning it can move in any direction without having to turn). I have been working on it for 2 years by now and will continue working on it through highschool as I develop my programming skills originally started off with just the base of the vehicle only having bare minimum features such as speed and direction control. As mentioned above, it is controlled by a custom application which I made in MIT App Inventor (ai2) and in the future I am planning to completely custom make the application in Android Studio using Kotlin and XML. I then later found out about Jetson nanos and I started integrating them in with for example the LiDAR being the first integration.

Although Project Silent Willow is the vehicle itself, the group of words ```Project Silent Willow``` represents a larger project (which includes this repository, other repositories [such as <a href="https://github.com/win21H2/Project-Silent-Willow-Main-Application">Project-Silent-Willow-Main-Application</a>], and my <a href="https://324hz.dev">main website</a>) which consists of multiple smaller projects such as the above mentioned and LiDAR scanning/data visualization.
### Technology involved
The main pieces of technology used include Arduinos, Nvidia Jetson nanos and a RPLiDAR A1M8 scanner although there are others such as DRV8825 (stepper motor drivers), shift registers, HC-05 BT modules, and stepper motors.
### The functions of Project Silent Willow

### Files in this repository

<a href="https://github.com/win21H2/Project-Silent-Willow/tree/main/main%20code">`/main code`</a><br/>
<a href="https://github.com/win21H2/Project-Silent-Willow/blob/main/main%20code/BTcontrol.ino">`main code/BTcontrol.ino`</a> => Bluetooth control<br/>
<a href="https://github.com/win21H2/Project-Silent-Willow/blob/main/main%20code/SRcontrol.ino">`main code/SRcontrol.ino`</a> => Serial control (from Nvidia Jetson nano)

<a href="https://github.com/win21H2/Project-Silent-Willow/tree/main/sample%20code">`/sample code`</a><br/>
<a href="https://github.com/win21H2/Project-Silent-Willow/blob/main/sample%20code/switchcase..ino">`sample code/switchcase.ino`</a> => Testing switch cases (serial and bluetooth control)

### Other repositories used in Project Silent Willow
<a href="https://github.com/win21H2/Project-Silent-Willow-Main-Application">Project-Silent-Willow-Main-Application</a><br/>
<a href="https://github.com/win21H2/Image-Recognition-win21H2">Image-Recognition-win21H2</a><br/>
