import math


D_values = [-59, -28, 0, 31, 61, 92, 122, 153, 184, 214, 245, 275]
ST_values = [9, 10.5, 12, 13.5, 15]

for D in D_values:
    for ST in ST_values:
        SINA = math.sin(2 * math.pi * (D / 365)) * math.sin((2 * math.pi / 360) * 23.45)
        COSA = math.sqrt(1 - SINA**2)
        COSW = math.cos((math.pi / 12) * (ST - 12))
        SINas = COSA * math.cos(math.radians(39.4)) * COSW + SINA * math.sin(math.radians(39.4))
        DNI = 1.366 * (0.34981 + 0.5783875 * math.exp(-0.275745 / SINas))
        print(f"D = {D}, ST = {ST}, DNI = {DNI}")