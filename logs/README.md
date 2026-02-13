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
- `Mon Feb 02 2026 07:55:20` : Estimate rough budget around ৳6K-৳7K. Budgetary breakdown:
  - GPS Module : ৳1200
  - Microcontrollers: ৳1000 (includes a combination of an esp32, arduino nano, pico)
  - Bluetooth modules: ৳300-৳600
  - Ultrasonic sensors: ৳400
  - OPTIONAL GSM: ৳700
  - Vibration motors: ৳400
- `Mon Feb 02 2026 11:04:51` : Present proposal, pushback about headwear. budget set at ৳6500
- `Wed Feb 04 2026 06:26:03` : Decide on RF 433mhz on being the way the two parts communicate, instead of bluetooth
- `Wed Feb 04 2026 21:26:03` : Plan either two ATMega328s or one ATMega328 and one ATTiny85 for the headband (needs a
  DEMUX to handle 8 vibration motors)
- `Thu Feb 05 2026 13:40:16` : Make purchase

| Item No |              Item Name               | Price per unit | Quantity | Total |                    Store                     |              Receipt              |                  Note                   |
| :-----: | :----------------------------------: | :------------: | :------: | :---: | :------------------------------------------: | :-------------------------------: | :-------------------------------------: |
|    1    |            Arduino Uno R3            |      ৳550      |    2     | ৳1100 |  Swadesh [Attachment_1](attachments/1.png)   | [Attachment_4](attachments/4.png) |    Two atmega328s for communication     |
|    2    | RF 433 receiver and transmitter pair |      ৳100      |    1     | ৳100  |  Swadesh [Attachment_1](attachments/1.png)   | [Attachment_4](attachments/4.png) | For communication between the two parts |
|    3    |                1n4148                |       ৳2       |    8     |  ৳16  |  Swadesh [Attachment_1](attachments/1.png)   | [Attachment_4](attachments/4.png) |         to prevent backfeeding          |
|    4    |                2n2222                |      ৳2.5      |    8     |  ৳20  |  Swadesh [Attachment_1](attachments/1.png)   | [Attachment_4](attachments/4.png) |         for the vibration motor         |
|    5    |               HC SR 04               |      ৳65       |    4     | ৳260  |  Swadesh [Attachment_1](attachments/1.png)   | [Attachment_4](attachments/4.png) |              Sonar sensors              |
|    6    |                 4056                 |      ৳15       |    1     |  ৳15  |  Swadesh [Attachment_1](attachments/1.png)   | [Attachment_4](attachments/4.png) |             Chargine module             |
|    7    |               MPU 6050               |      ৳170      |    1     | ৳170  |  Swadesh [Attachment_1](attachments/1.png)   | [Attachment_4](attachments/4.png) |            Gyroscope sensor             |
|    8    |                Neo-6m                |      ৳330      |    1     | ৳330  |  Swadesh [Attachment_1](attachments/1.png)   | [Attachment_4](attachments/4.png) |               GPS Module                |
|    9    |           3.7 1000Mhz LiPo           |      ৳140      |    1     | ৳140  | AbdusSalam [Attachment_2](attachments/5.png) | [Attachment_5](attachments/5.png) |          Battery for headgear           |
|   10    |           28 pin IC holder           |      ৳10       |    2     |  ৳20  | AbdusSalam [Attachment_2](attachments/5.png) | [Attachment_5](attachments/5.png) |            For arduino chips            |
|   11    |        Coin vibration motors         |      ৳75       |    4     | ৳300  |   Mannan [Attachment_3](attachments/2.png)   |                ❌                 |      Haptic feedback; Need 4 more       |
|         |                Total                 |                |    33    | ৳2471 |                                              |                                   |                                         |

- `Thu Feb 05 2026 16:03:20` : Started Logging
- `Thu Feb 05 2026 18:55:20` : Blink Test passed for both UNOs <img alt="6" src="./attachments/6.jpeg" />

> lackluster entry made to be exemplary of how future entries go. (I need two UNOs because i'll be coding two
> simultaneously and will be testing to see them communicate), otherwise I'd just use one UNO to program different
> ATMega328s

- `Thu Feb 05 2026 19:35:10` : Bootload to every ATMega328 chip. `Thu Feb 05 2026 20:18:01` : Successfully established
  connection between two UNOs using RF
  [Commit](https://github.com/hamzahossain/OmniNav/commit/4007010bf32ae897c1e7cfd6a1b7ddbcb73898d0)
  <img alt="7" src="./attachments/7.jpeg"/>

- `Thu Feb 05 2026 20:25:01` : To Make the atmega run standalone, i require
  - 16Mhz crystal oscillator
  - 22 pF ceramic capacitor (2)
  - 10 kOhm
  - 0.1 µF (3)
- `Thu Feb 05 2026 20:25:01` : For better RF performance, I need antennas
  `RF - 433MHz Helical Spring Antenna for Wireless Modules 2`
- `Fri Feb 06 2026 16:16:33` : The RF receiver has to have the ground connected to the chip's ground for some reason.
- `Fri Feb 06 2026 16:29:45` : Added keypad to transmitter to simulate dynamic directional input.
  [27dd4ac](https://github.com/hamzahossain/OmniNav/commit/27dd4ac302e5c6d990c6b570a41c689d82d74303)
- `Fri Feb 06 2026 18:35:45` : Made the workspace cleaner (combined the two breadboards. the RF works, there's no point
  in demonstrating that anymore). <img alt="8" src="./attachments/8.jpeg"/>

- `Fri Feb 06 2026 18:45:21` : Started coin vibration motor testing (PLAN: use the keypads to simulate test the
  intensities, 1-9 = 10%=90%)
- `Fri Feb 06 2026 22:27:42` : SETBACK: Can't get Coin motors to work.
- `Sat Feb 07 2026 18:48:17` : From simulation, I found that the problem is the PWM isn't giving enough voltage
  <img width="1697" height="723" alt="image" src="https://github.com/user-attachments/assets/dfb86c65-952a-41d4-9e34-8c56086dfbe6" />
  Addendum - I found the minimum (IN SIMULATION) value to be 120; learned something about a kickstarting value; Current
  plan: starting value will be the lowest feelable value (TO TEST), max value will be the most tolerable (accounting for
  hair)
- `Sat Feb 07 2026 19:47:20` : FIXED Motor usage. **PROBLEM: RadioHead messes with pin 9 and 10 internally**
- `Sat Feb 07 2026 19:55:43` : Addressable intensity feature added, however... it just feels the same.
- `Sat Feb 07 2026 20:07:26` : Momma hamza also said it felt the same, so... I guess human fingertip perception can't
  tell the levels apart (FUTURE implementation: stronger vibration motors OR maybe the skin on the forehead is more
  sensitive? To revisit)
- `Sat Feb 07 2026 20:33:54` : Used delay to simulate intensity
  [#dbd09cd](https://github.com/hamzahossain/OmniNav/commit/dbd09cddd6948f5016520e64032f19d8bcc87789)
- `Sat Feb 07 2026 21:39:57` : Plan for directional motor layout <img alt="9" src="./attachments/9.png"/>
- `Sat Feb 07 2026 22:03:26` : Successfully tested dynamic directional input. <img alt="10" src="./attachments/10.jpg"/>
- `Sun Feb 08 2026 14:15:49` : Purchashed: (NOTE: A lot of the components were small and dirt cheap. they were bundled
  up and charged at an amount of like 30tk. Due to the amount of it, I didn't get a proper receipt. just a sign with the
  amount written by the shopkeeper... I.. ended up purchasing more even after that), [Attachment_15](attachments/15.png)

| Item No |        Item Name         | Price per unit | Quantity | Total |                   Store                   |               Receipt               |            Note             |
| :-----: | :----------------------: | :------------: | :------: | :---: | :---------------------------------------: | :---------------------------------: | :-------------------------: |
|    1    | 16mhz crystal oscillator |      ৳10       |    4     |  ৳40  | Swadesh [Attachment_1](attachments/1.png) | [Attachment_15](attachments/15.png) |         Uno onboard         |
|    2    |        Veroboard         |      ৳50       |    2     | ৳100  | Swadesh [Attachment_1](attachments/1.png) | [Attachment_15](attachments/15.png) |         Uno onboard         |
|    3    |           22pF           |     ৳1.25      |    8     |  ৳10  | Swadesh [Attachment_1](attachments/1.png) | [Attachment_15](attachments/15.png) |         Uno onboard         |
|    4    |          0.1uF           |     ৳1.25      |    12    |  ৳15  | Swadesh [Attachment_1](attachments/1.png) | [Attachment_15](attachments/15.png) |         Uno onboard         |
|    5    |           10uF           |       ৳1       |    5     |  ৳ 5  | Swadesh [Attachment_1](attachments/1.png) | [Attachment_15](attachments/15.png) |         Uno onboard         |
|    6    |           10KΩ           |      ৳1.5      |    20    |  ৳30  | Swadesh [Attachment_1](attachments/1.png) | [Attachment_15](attachments/15.png) |         Uno onboard         |
|    7    |           330Ω           |       ৳1       |    30    |  ৳30  | Swadesh [Attachment_1](attachments/1.png) | [Attachment_15](attachments/15.png) |      Current limiting       |
|    8    |           LED            |       ৳1       |    10    |  ৳10  | Swadesh [Attachment_1](attachments/1.png) | [Attachment_15](attachments/15.png) |           Testing           |
|    9    |        USB TO TTL        |      ৳80       |    2     | ৳160  | Swadesh [Attachment_1](attachments/1.png) | [Attachment_15](attachments/15.png) | To code the UNOs on the fly |
|   10    |     Boost Converter      |      ৳60       |    1     |  ৳60  | Swadesh [Attachment_1](attachments/1.png) | [Attachment_15](attachments/15.png) |             5v              |
|   11    |          TP4056          |      ৳15       |    1     |  ৳15  | Swadesh [Attachment_1](attachments/1.png) | [Attachment_15](attachments/15.png) |          Charging           |
|   12    |        9v Battery        |      ৳40       |    1     |  ৳40  | Swadesh [Attachment_1](attachments/1.png) | [Attachment_15](attachments/15.png) |            Power            |
|   13    |     Breadboard large     |      ৳80       |    1     |  ৳80  | Swadesh [Attachment_1](attachments/1.png) | [Attachment_15](attachments/15.png) |           Testing           |
|         |          Total           |                |    97    | ৳595  |                                           |                                     |      ACC Total: ৳3066       |

- `Sun Feb 08 2026 18:21:49` : Successfully detached the ATMega328 to a standalone setup.
  <img alt="11" src="./attachments/11.png"/>
- `Sun Feb 08 2026 18:50:34` : Rolled back to
  [legacy driver for the USB-> TTL](https://github.com/johnstevenson/pl2303-legacy)
- `Thu Feb 12 2026 10:51:09` : The HC-SR04 (sonar) sensors up to 30 degrees. need more than 4 for total coverage
  apparently.
- `Thu Feb 12 2026 17:06:48` : For the Sonar sensors, all of them can share the same trigger pin but the echo pins
  should be separate.
- `Thu Feb 12 2026 17:07:48` : Might need to switch to ESP32, The GPS, the gyro. and the sonars add up to a lot of
  switches.
- `Thu Feb 12 2026 18:45:49` : NOTE: IMEI complications on GSM Module. Current plans. just connect to phone over BLE.
- `Fri Feb 13 2026 14:10:34` : Try `VeeCad`
- `Fri Feb 13 2026 14:38:15` : Can't show the background wiring in VeeCad. Move to `VeroRoute`.
- `Fri Feb 13 2026 15:07:24` : Use threads for strap ![alt text](./attachments/12.png)
- `Fri Feb 13 2026 16:23:53` : Designated Pins for motors \

**MOTOR NUMBERING**:

| Motor Number | Motor Direction |
| :----------: | :-------------: |
|      0       |        F        |
|      1       |       LF        |
|      2       |        L        |
|      3       |       LD        |
|      4       |        D        |
|      5       |       RD        |
|      6       |        R        |
|      7       |       RF        |

**PIN DESIGNATION**:

| ATMega PIN | Arduino PIN | Motor Number |
| :--------: | :---------: | :----------: |
|     19     |     13      |      0       |
|     18     |     12      |      1       |
|     17     |     11      |      2       |
|     15     |      9      |      3       |
|     11     |      5      |      4       |
|     12     |      6      |      5       |
|     13     |      8      |      6       |
|     14     |      8      |      7       |
|     16     |     10      |  RF Receive  |

- `Fri Feb 13 2026 18:12:26` : Draft head base

![13 png](./attachments/13.png)

- `Fri Feb 13 2026 19:38:14` : Finalize Headgear Base

![14 png](./attachments/14.png)

- `Fri Feb 13 2026 22:28:34` : Finalize Headgear Motor

![16 png](./attachments/16.png)

- `Fri Feb 13 2026 23:42:16` : Rework base

![17 png](./attachments/17.png)

- `Sat Feb 14 2026 00:18:49` : Example of the wiring for a specific motor, in this example: `LD` :

![Temp](https://github.com/user-attachments/assets/dad074b0-94a2-4351-81de-b7b674843286)

Just make the base and solder to the specific direction 
# Format

The time format is `GMT + 0600 (BST)`,\
৳currency = `BDT`

# Log Scripts

```js
// generating timestamp script
copy(`- \`${new Date().toString().split(" ").slice(0, 5).join(" ")}\` : `);
```

```js
// GENERATING MARKDOWN TABLE
function generateMDTable(arr) {
  let fr = arr.shift();
  arr.unshift(Array.from({ length: arr[0].length }, () => ":---:"));
  arr.unshift(fr);
  let res = ``;
  for (let i = 0; i < arr.length; i++) {
    res += "|";
    for (let j = 0; j < arr[0].length; j++) {
      res += `${arr[i][j] ?? ""}|`;
    }
    res += "\n";
  }
  return res;
}
```

```js
// GENERATING INVOICE TABLE
//  "Item Name", "Price per unit", "Quantity", "Store", "Receipt", "Note"
/*
[
["Uno R3", "520", "2", "Swadesh a!1", "a!3", "Two atmega328s for communication"],
["RF 433 receiver and transmitter pair", "100", "1", "Swadesh a!1", "a!2", "For communication between the two parts"],
["1n4148", "2", '8', 'Swadesh a!1', 'a!3', 'to prevent backfeeding'],
["2n2222", "2.5", '8', 'Swadesh a!1', 'a!3', 'for the vibration motor'],
]
*/

function generateInvoicesTable(ar) {
  const categories = [
    "Item No",
    "Item Name",
    "Price per unit",
    "Quantity",
    "Total",
    "Store",
    "Receipt",
    "Note",
  ];
  let totalPrice = 0;
  let totalQuan = 0;
  ar.forEach((a, i) => {
    a.unshift(i + 1);
    const paid = a[3] * a[2];
    a.splice(4, 0, paid);
    totalPrice += paid;
    totalQuan += +a[3];
    if (a.length != categories.length) throw new Error("Mismatch");
    if (a[6].includes("a!")) {
      const spl = a[6].split("a!");
      a[6] = `${spl[0].trim()} [Attachment_${spl[1]}](attachments/${spl[1]}.png)`;
    }
    if (a[5].includes("a!")) {
      const spl = a[5].split("a!");
      a[5] = `${spl[0].trim()} [Attachment_${spl[1]}](attachments/${spl[1]}.png)`;
    }
  });

  ar.unshift([]); // padding
  ar.unshift(categories);
  for (let i = 0; i < categories.length; i++) {
    ar[1].push(":---:"); // center
  }
  ar.push(Array.from({ lenghth: categories.length }).fill(""));
  ar.at(-1)[1] = "Total";
  ar.at(-1)[3] = totalQuan;
  ar.at(-1)[4] = totalPrice;
  let res = ``;
  for (let i = 0; i < ar.length; i++) {
    res += "|";
    for (let j = 0; j < ar[0].length; j++) {
      res += `${ar[i][j] ?? ""}|`;
    }
    res += "\n";
  }
  return res;
}
```

# ⚠️ DISCLAIMER

A few of the receipts weren't recoverable. The point of keeping the receipts is for budgetary accountability  
And the prices here are strictly what I have paid for them. These may change over time. The sources are linked but due
to buying wholesale and haggling and at times being a regular customer, I got some of the components at a cheaper price.
Some components I bought for my personal usage, which are just there in the receipts. they may be ignored. Some
components are bought to be extras. some may not be present at the final build. there will be a final component sheet
with total build cost, independant from how much I spent on this project along the way.
