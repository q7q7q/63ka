<img width="1410" height="2000" alt="63ka (2)" src="https://github.com/user-attachments/assets/bb59b6bc-12e5-4aeb-b9d9-300888795cea" />

# 63ka
With the power of exponents, 63ka can let you can set a timer of any integer (that is positive ofc) from 1~63 minutes!
I made this project because I want a minimalistic style, small study-timer, and also help me understand about PCB circuit boards better along the way.
What I'm aiming to make is a ~63 minute timer, with only 6 buttons (very minimalistic design). This works because I have assigned different values to each button (1, 2, 4, 8, 16, 32), so that there is a possible combination when you want to set a timer for whatever minutes you want as long as its integer, and ~63. The timers stack. 
If you press a button, (1, 2, 4, 8, 16, or 32 min button), that will trigger the LED switch to set a timer for __ minutes. For example, if you want to set a timer for 40 minutes, press the 32 minute button, and the 8 minute button.
The pcb's appearance is always the timer's seconds, rounded up. (if theres 4 minutes and 50 seconds left on timer, leds for 1 and 4 minute will flash up, which results in 5 minutes)
When you want to add/remove an amount, press buttons to update the binary number left on timer. 
When the timer reaches zero, it produces a calm frequency 8 times. 

## HOW I BUILT IT
Because I was new to building schematics/PCB's, I had to research a lot. 
For my microcontroller I used the RP2040 tiny. (because there are not many inputs I need to plug in)
<img width="609" height="345" alt="Screenshot 2026-04-17 at 10 40 19 PM" src="https://github.com/user-attachments/assets/5e36c4a4-3ff0-4af6-8155-916e7d5639be" />
finished schmeatic design



<img width="1094" height="597" alt="Screenshot 2026-04-17 at 9 25 36 PM" src="https://github.com/user-attachments/assets/e5496766-e00b-4f18-adfc-abee85c88d58" />

<img width="690" height="362" alt="63ka" src="https://github.com/user-attachments/assets/9779f9a9-2088-4b27-9f45-7f44d7d58ed2" />

