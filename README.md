<a id="readme"></a>
<p align="center"><img src="img/CavAirMiniTitle.jpg"></p>

<p align="center">
    <img src="https://img.shields.io/badge/MCU-ATMega328P-blue" />
    <img src="https://img.shields.io/badge/Framework-Arduino-00979D?logo=arduino&logoColor=white" />
    <img src="https://img.shields.io/badge/Platform-PlatformIO-ff6600?logo=platformio&logoColor=white" />
    <img src="https://img.shields.io/badge/status-COMPLETE-22783C" />
    <br>
    <img src="https://img.shields.io/badge/Programmer-UPDI-B9BEC3" />
    <img src="https://img.shields.io/badge/Bus-I2C-c66a00" />
    <img src="https://img.shields.io/badge/Bus-UART-c66a00" />
    <img src="https://img.shields.io/badge/Storage-EEPROM-9B91AA" />
    <br>
    <img src="https://img.shields.io/badge/CO₂-SCD40-3399ff" />
    <img src="https://img.shields.io/badge/Display-SSD1306-6E75C8" />
    <img src="https://img.shields.io/badge/Power-Lithium-c44536" />
</p>

---

> **NOTE:** This is a shallow copy of the working (private) repository and does not contain the guts of the source code for this project.  If you're interested in working on an actual CavAirMini, please reach out to the author.

# Project Overview

Somewhat unique to Texas, some caves we explore can only be entered during the winter months.  During the summer, layers of CO2 can stratify in the lower reaches of the cave and create a potentially dangerous situation, especially if it is a vertical cave where cavers need to be on-rope to descend into the cave.  The layer can be quite pronounced - sometimes the air at your head can be good while the air at your feet can be dangerous to be in.

Commercial CO2 monitors are available but tend to be very expensive - most times out of the reach of a typical caver's budget.  The commonly accepted practice is to use a lighter to determine if the air is bad - if the lighter will not light, or if the flame hovers a few inches above the lighter, CO2 is present.  This isn't ideal because it requires the lighter operator to actually be in bad air before it can be detected.  A better solution was needed.

<table border="0" style="border:none;" cellpadding="0" cellspacing="0"><tr>
<td style="padding:0; border:none;" width="80%">
This project is an evolution of the <a href="https://github.com/RedHatJef/CavAir#readme">CavAir</a>, a top-secret Christmas present for my wife.  The goal of this project is to take the lessons learned from that project and build a smaller, more practical device that cavers can both take with them into a cave as both an monitoring and alerting system.
<br><br>
Additionally, being able to drop the sensor into a cave before entering is ideal - having the device detect bad air and save the min/max readings so cavers can see if the cave is safe to enter.  The picture below demonstrates this technique, dog provided for scale.
</td>
<td style="border:none;" valign="middle" align="center">
<img src="img/CavAirMiniWithElla.jpg" alt="CavAirMini line drop method being tested with my un-interested dog Ella"></td>
</tr></table>

# Project Requirements

* Smaller
  * Use a "PET bottle preform" (a small plastic test tube) for the case[^1]
  * Custom PCB with TQFP ATMega328P instead of Ardunio Nano
  * Direct-wire battery instead of battery carrier
* Ability to use while "closed"
  * Create a cap that allows for gasses to pass through while keeping most of the system safe
  * Attachment points for securing to a line or caving gear
* Critical Sensors Only
  * No more O2 sensor (size issues)
* Monitoring & Alerting
  * Display visible through preform
  * Flashing LEDs for alerting
  * Buzzer for alarms at various CO2 levels
* Configuration
  * Menus for calibration and user preferences
  * Serial number and other information at boot

# Prototype

Getting the CO2 sensor up and running was easy.  Building an interface that humans would receive well was hard.

<p align="center">
<img src="img/CavAirMiniPrototypeTest.jpg" width="65%">
</p>

### Major programming hurdles/decisions
* Create a splash screen by digitizing custom art into an array of bits that could be displayed.  (wrote utility program to take in start/finish numbers for each row and output C++ code with an array of numbers)
* LED codes - what kind of standards are there, what's eye catching, what will tell users "danger"?  Is "just blinking red" good enough?
* Beep codes - at what threshold are cavers OK with getting constant beeps from medium-level CO2?  Should this be tunable?
* What kind of information should be displayed on the screen?
* What kind of user calibration should be allowed?  How do you set altitude/pressure, which the sensor requires?
* What units should be displayed?  PPM or Percent?  (both don't fit)
* How do you calculate battery percentage?
* What should be stored in serial EEPROM and retained across boots?
* How to display and reset min/max CO2 values?
* Should temperature be displayed?  Is it accurate enough?  (seems like it is always offset)
* Display libraries are very resource intensive (mostly ROM space, but some RAM).  What is absolutely necessary?
* Menu systems should be flexible but not difficult to maintain/build.  Adding menu options should be adding something to an array - not rewiring a state machine.

# Construction

## Enclosure (preform)

Finding PET preforms in the right size and thickness was a huge win for this project.  Several batches of preforms were ordered.  Thinner walled versions (likely for 12/16 oz sodas) allowed for more space for the electronics but were prone to breakage.  Thicker walled versions (likely for 2L bottles) could withstand a truck driving over them, but required more careful/smller PCB design to fit.

## Cap

Once a good PET preform was sourced, a cap for the device was necessary.  This proved challenging because there are so many variations of thread designs.  Many prototypes were designed and printed before a workable matching cap thread was made.[^2]

<table border="0" style="border:none;" cellpadding="0" cellspacing="0"><tr>
<td style="padding:0; border:none;">
Additionally, one of the requirements was to be able to use the device while in its "closed" configuration.  Instead of just having an open hole at the top, something that could be "splash proof" and keep some dirt out of the device would be nice.  The cap was designed to accept a "mushroom filter and cap" - typically used for growing mushrooms in ball jars.  This included a paper filter sticker and a rubber cap.
</td>
<td style="border:none;" valign="middle" align="center">
<img src="https://m.media-amazon.com/images/I/71R9cqhMopL._AC_SL1500_.jpg" width="50%">
</td>
</tr></table>

The cap is designed to place a mushroom filter on the inner cap, and keep a rubber cap on the outer cap.  Holes on the outer cap allow for cave line to be used to attach the CavAir to a carabiner.

<table border="0" style="border:none;" cellpadding="0" cellspacing="0"><tr>
<td style="border:none;">
<img src="img/CavAirCap_Top.jpg">
</td>
<td style="border:none;">
<img src="img/CavAirCap_Bottom.jpg">
</td>
</tr></table>

Coming Soon: Close-up of dirty cavair cap and plug

## PCB Design

[KiCAD](https://www.kicad.org/) was used for schematic capture and PCB design.

Before any PCBs were designed, a 3d model mock-up was created in Fusion360 to test fit.

<table border="0" style="border:none;" cellpadding="0" cellspacing="0"><tr>
<td style="border:none;">
<img src="img/CavAirMiniMockUp.jpg">
</td>
<td style="border:none;">
<img src="img/CavAirMiniMockUp2.jpg">
</td>
</tr></table>

### Version 1/2

This was the first version designed and manufactured, and was the actual Christmas gift model.  Given the short timelines, I elected to use a ready-made battery charger breakoutboard.  Later on I learned that this board was both almost too large for the preform, but also didn't like some usb-c charging cables.

Versioning on these boards start with 2 - a version 1 was created but not manufactured.

![Version 2 Top](img/pcb/PCB_CavAirMini2_Top.png)
![Version 2 Bottom](img/pcb/PCB_CavAirMini2_Bottom.png)

Unfortunately, a bug in the PCB design resulted in the board not powering up.  After a couple of hours of debugging and fretting, a temporary hack was found that allowed the boards to run.

<p align="center">
<img src="img/CavAirMiniPCBv1Fix.jpeg" width="50%">
</p>

Fully assembled and running version 1 board.

<table border="0" style="border:none;" cellpadding="0" cellspacing="0"><tr>
<td style="border:none;">
<img src="img/CavAirMiniWithTube.jpg">
</td>
<td style="border:none;">
<img src="img/CavAirMiniInTube.jpg">
</td>
</tr></table>

Note that this version has a hole in the PCB for the buzzer.  In practice, this meant the PCB was a bit too long for the board.  Fortunately there were no wires going through this part of the PCB and I wound up removing the edge near the buzzer to make things fit into the tube better.

### Version 3

The goal of this version was to replace the battery charging board with a battery charging circuit directly on the board, as well as fixing the initial power supply hack.  Additionally, flipping the CO2 sensor over so it stuck through the board would make fitment significantly better, plus potentially help with gas diffusion into and out of the CO2 sensor.  The black square you see below is the cutout for the sensor.  Finally, finding a way to shorten the overall board a bit was important - it's tight in that tube!

![Version 3 Top](img/pcb/PCB_CavAirMini3_Top.png)
![Version 3 Bottom](img/pcb/PCB_CavAirMini3_Bottom.png)

Assembled board being tested, note the flipped CO2 carrier board and sensor sticking through the board.

<table border="0" style="border:none;" cellpadding="0" cellspacing="0"><tr>
<td style="border:none;">
<img src="img/CavAirMiniPCBv3Test1.jpg">
</td>
<td style="border:none;">
<img src="img/CavAirMiniPCBv3Test2.jpg">
</td>
</tr></table>

### Version 3.1

The goal of this version was to add some debugging ports onto the board as well as to taper the end of the board so it fit better into the preform.

![Version 3 Top](img/pcb/PCB_CavAirMini3_1_Top.png)
![Version 3 Bottom](img/pcb/PCB_CavAirMini3_1_Bottom.png)

It's always a fun time getting new boards in and assembling them.  All of the parts used on all versions of this board were hand-soldered.  (no reflow oven, although that's the next step...)

<table border="0" style="border:none;" cellpadding="0" cellspacing="0"><tr>
<td style="border:none;" align="center" valign="middle">
<img src="img/CavAirMiniPCBv3Microscope.jpg">
</td>
<td style="border:none;" align="center" valign="middle">
<img src="img/CavAirMiniPCBv3.jpg">
</td>
</tr></table>

# Marketing

As part of the Christmas surprise, I really wanted to be able to make this present look like an "off the shelf" product.

## Boot/Splash Screen

I worked with a local artist to make a splash screen for the device.  

Coming soon: Original splash screen sketch

## User Manual & YouTube Video

Of course I needed a user manual.  A friend and local photographer helped me to get some professional pictures for the manual.  Assembling the manual was fun, but I ran into a critical issue where it was impossible to take pictures of the screen to document various menu features and operational modes.  

After a bit of thinking, I was able to wire in a special command on the serial port to tell the device to take a "screen shot" of the current in-memory screen data and spit it out in CSV format to the console.  I wrote a second utility to process the CSV data into a PBM file[^3] which I could then convert into a PNG to paste into the manual.

<table border="0" style="border:none;" cellpadding="0" cellspacing="0">
<tr>
<td style="border:none;" align="center" valign="middle">
<img src="img/marketing/MainDisplayDiagram.png" valign="middle" align="center">
</td>
<td style="border:none;" align="center" valign="middle">
<img src="img/marketing/BootFlow.jpg" valign="middle" align="center">
</td>
</tr>
<tr>
<td style="border:none;" align="center" valign="middle">
<img src="img/marketing/Calibration.jpg" valign="middle" align="center">
</td>
<td style="border:none;" align="center" valign="middle">
<img src="img/marketing/Appendix.jpg" valign="middle" align="center">
</td>
</tr>
</table>

In addition, a [YouTube video](https://youtu.be/yEi0v3Xhb24) was created, with a QR code on the box linking to it.

## Packaging

Coming Soon: Box and insert, plastic wrapped device, etc.

# Reception

Christmas Day was a fun time.  As expected, my wife was confused and surprised - she'd never heard of a "CavAir" and at first didn't know what it was.  She was super excited to turn it on and see her daughter's artwork as the splash image, and couldn't wait to get it underground and use it.

<table border="0" style="border:none;" cellpadding="0" cellspacing="0">
<tr>
<td style="border:none;" align="center" valign="middle">
<img src="img/Gift2.jpg" valign="middle" align="center">
</td>
<td style="border:none;" align="center" valign="middle">
<img src="img/Gift1.jpg" valign="middle" align="center">
</td>
</tr>
</table>

# Real-World Use

Half a dozen units have been deployed to the field for about two years now, and have seen a lot of use.

<p align="center">
<img src="img/DirtyCavAirMini.jpg" width="65%">
</p>

Coming Soon: Dirty and broken parts

## Disco Cave

<p align="center">
<img src="img/DiscoCave.jpg" width="65%">
</p>

A friend of mine used his CavAirMini extensively in San Saba County, TX - where many caves have dangerous levels of CO2.  On one particular day, they discovered a new cave, lowered the CavAir into it, and the CavAir immediately started beeping and flashing.  When they pulled the CavAir back out of the cave, it had maxed out the reading at over 4.5%.  The cave was later named "Disco Cave" because the CavAir started flashing and beeping in ultimate alert mode after it was lowered into the cave.  Needless to say, they didn't enter the cave that day.  

## NCRC

A couple of times a year, cavers attend training with the NCRC - learning how to rescue injured cavers in a cave and while on rope.  It's difficult training and is sometimes conducted in caves with noticable levels of CO2.  Several units have been used for this training event, ensuring that participants are not in danger while they conduct mock rescue drills.

## Other Caving

I've had the opportunity to take a CavAir into several caves in both Florida and Texas - where the readings were non-zero.  Generally as we descended into the cave, the levels increased.  In one case we elected to turn the trip because the level had gotten too high for everyone to be comfortable.  It should be said that in that case, the lighter trick was not indicating any issues, but the CavAir was showing CO2.

I was also able to put the waterproof cap on a CavAir and take it cave diving - over 4000 feet into an underwater cave - and test the air in an air bell (sump).  I think this is the first time the air in that sump was tested, and absolutely the first time it was used in conjunction with a cave dive.  This is handy information - knowing whether or not a sump is a safe place to consider an exit point in case of a diving emergency is always nice.

# Next Steps

## CavAirMicro?

I really like the size of the CavAirMini, but what if we could make an even smaller model?
* No daughter boards - use reflow oven to use parts directly
* Smaller buzzer and LED modules
* Smaller battery
* No display - potentially more complicated blinking code or tap-to-give-reading functionality

<p align="center">
<img src="img/CavAirMicroPrototype.jpg" width="65%">
</p>

## CavAirPro

There's still some users who want to use a galvanic O2 sensor, but this will increase the size of the enclosure.  I've recently found a larger preform that would fix this sensor, but it will require some work to make the sensor, a new board design, and a battery - fit.  And of course, a new cap would be necessary.

## Are these for sale?

No.  A couple of challenges exist.
1. The license for Fusion360 would need to be upgraded to a non-free model in order to sell anything made with the program.
2. Liability is a major concern.
3. Do I really want to support these products long-term?

# Credits

CavAirMini manual pictures and some of these page images by Genevieve Daniell — see more of her work at [www.genevievedaniell.com](http://www.genevievedaniell.com)

Real world pictures from Ryan Hoffman, fellow caver.


[^1]: [Preforms](https://www.amazon.com/Soda-Bottle-Preforms-Caps-30/dp/B008MB1QNY) are what soda bottles start life as.  They're heated up and then air pressure is used to form them into a soda bottle mold.  In their non-expanded state, these are almost completely unbreakable, and an ideal size for carrying things like two 18650 batteries.  They're also waterproof when the cap is installed.
[^2]: [28mm soda bottle cap thread diagram](https://modulpac.se/wp-content/uploads/28phals.pdf)
[^3]: [A plain text file format](https://oceancolor.gsfc.nasa.gov/staff/norman/seawifs_image_cookbook/faux_shuttle/pbm.html) that's easy to write for basic images like this. 