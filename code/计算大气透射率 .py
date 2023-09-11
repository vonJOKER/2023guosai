import csv
import math


with open('附件1.csv', mode='r') as csv_file, open('大气透射率.csv', mode='w', newline='') as new_csv_file:
    csv_reader = csv.reader(csv_file)
    csv_writer = csv.writer(new_csv_file)


    header = next(csv_reader)

    csv_writer.writerow(['X坐标', 'Y坐标', 'DHR','大气透射率'])


    for row in csv_reader:
        x = float(row[0])
        y = float(row[1])
        DHR = math.sqrt(x ** 2 + y ** 2 + 76 ** 2)
        at = 0.99321 - 0.0001176 * DHR + 1.97e-8 * DHR ** 2
        csv_writer.writerow([x, y, DHR, at])
