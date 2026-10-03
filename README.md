# Smart Plant Care — IoT OST Practice Version 1.0

Prepared by **Prof. Dinesh S. Auti, Department of EXCP, KJSSE**.

Interactive digital twin for analog sensing, calibration, hysteresis, relay interfacing, pump protection, code tracing and fault diagnosis.

## GitHub Pages

Upload `index.html`, `styles.css` and `app.js` to the repository root. Under **Settings → Pages**, select **Deploy from a branch**, `main`, and `/(root)`.

## Reference hardware

- Arduino Uno
- Capacitive soil-moisture sensor → A0
- DHT11 → D2
- Tank float switch → D7 with `INPUT_PULLUP`
- 5 V relay module → D8
- Mini DC pump with a suitable separate supply

## Control logic

- Start below 35% moisture when water is available.
- Stop at or above 55% moisture.
- Empty tank or invalid sensor state forces the pump OFF.
- Separate ON/OFF thresholds provide hysteresis.

## Safety

Never power a pump directly from an Arduino GPIO. Use a relay/MOSFET driver, external supply and protection components.
