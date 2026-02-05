# LOG
- `Mon Feb 02 2026 07:35:20` : Project inception
- `Mon Feb 02 2026 07:44:20` : `OmniNav` naming
- `Mon Feb 02 2026 07:52:20` : Set constraints as
- - Lightweight
  - Comfortable
  - Easy to calibrate
  - Uses the bare minimum of human senses. (Currently, only the sensation of touch surrounding the forehead)
  - Intuitive/Easy to get used to.
  - Be as standalone as possible (Emergency contact requires internet and connectivity)
  - Doesn’t make the user stand out.
  - Easy to replicate/mass produce
- `Mon Feb 02 2026 07:55:20` : Estimate rough budget around $6K-$7K. Budgetary breakdown: 
  - GPS Module : $1200
  - Microcontrollers: $1000 (includes a combination of an esp32, arduino nano, pico)
  - Bluetooth modules: $300-$600
  - Ultrasonic sensors: $400
  - OPTIONAL GSM: $700
  - Vibration motors: $400
- `Mon Feb 02 2026 11:04:51` : Present proposal, pushback about headwear. budget set at $6500
- `Wed Feb 04 2026 06:26:03` : Decide on RF 433mhz on being the way the two parts communicate, instead of bluetooth
- `Wed Feb 04 2026 21:26:03` : Plan either two ATMega328s or one ATMega328 and one ATTiny85 for the headband (needs a DEMUX to handle 8 vibration motors)
- `Thu Feb 05 2026 16:03:20` : Started Logging

# Format
The time format is `GMT + 0600 (BST)`,\
$currency = `BDT`

# Log Scripts <img width="146" height="66" alt="image" src="https://github.com/user-attachments/assets/eead842b-3067-426e-a3cf-b4b1ee78bd0b" />


```js
// generating timestamp script 
copy(`- \`${new Date().toString().split(' ').slice(0, 5).join(" ")}\` : `)
```
