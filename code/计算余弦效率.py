import math
import csv

x_values = []
y_values = []

with open('附件.csv', 'r') as csv_file:
    csv_reader = csv.reader(csv_file)
    next(csv_reader)
    for row in csv_reader:
        x_values.append(float(row[0]))
        y_values.append(float(row[1]))

D_values = [-59, -28, 0, 31, 61, 92, 122, 153, 184, 214, 245, 275]
ST_values = [9, 10.5, 12, 13.5, 15]


cosine_efficiency = {}


for D in D_values:
    for ST in ST_values:
        SINA = math.sin(2 * math.pi * (D / 365)) * math.sin((2 * math.pi / 360) * 23.45)
        COSA = math.sqrt(1 - SINA ** 2)
        COSW = math.cos((math.pi / 12) * (ST - 12))
        cos_efficiency_values = []  
        for x, y in zip(x_values, y_values):
            SINas = COSA * math.cos(math.radians(39.4)) * COSW + SINA * math.sin(math.radians(39.4))
            COSas = math.sqrt(1 - SINas ** 2)
            COSgs = (SINA - SINas * math.sin(math.radians(39.4))) / (
                    math.sqrt(1 - SINas ** 2) * math.cos(math.radians(39.4)))
            COSAA = (SINA - SINas * math.sin(math.radians(39.4))) / COSas * math.cos(math.radians(39.4))
            SINAA = math.sqrt(1 - COSAA ** 2)
            COS2O = (-x * math.sqrt(1 - SINas ** 2) * SINAA - y * math.sqrt(1 - SINas ** 2) * math.sqrt(
                1 - SINAA ** 2) + 80 * SINas) / math.sqrt(x ** 2 + y ** 2 + 80 ** 2)
            COSO = math.sqrt((1 + COS2O) / 2)
            cos_efficiency_values.append(COSO)

     
        key = f'D{D}_ST{ST}'
        cosine_efficiency[key] = cos_efficiency_values

with open('结果1.csv', 'w', newline='') as result_file:
    csv_writer = csv.writer(result_file)
    header = ['D', 'ST'] + [f'余弦效率_{i}' for i in range(1, len(cosine_efficiency['D-59_ST9']) + 1)]
    csv_writer.writerow(header)

    for D in D_values:
        for ST in ST_values:
            key = f'D{D}_ST{ST}'
            row_data = [D, ST] + cosine_efficiency[key]
            csv_writer.writerow(row_data)

print("数据已保存到结果.csv文件中。")
