import matplotlib.pyplot as plt

with open("radix_stat.txt","r") as f:
    radix = f.read()

radix=radix.split('\n')
radix.pop()
x = [row.split(" ")[0] for row in radix]
y = [row.split(" ")[1] for row in radix]

line1, = plt.plot(x, y, "r", label='radixSort')
plt.legend(handles=[line1])
plt.title('Comparison of sort algorithms by inserts')
plt.xlabel('Number of elements')
plt.ylabel('Number of inserts')
plt.grid(True)
plt.show()