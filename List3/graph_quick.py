import matplotlib.pyplot as plt

with open("cmake-build-debug\outqs.txt", "r") as f:
    quicksortmedian = f.read()
with open("cmake-build-debug\outq.txt", "r") as f:
    quicksort = f.read()

quicksortmedian = quicksortmedian.split('\n')
quicksortmedian.pop()
quicksort = quicksort.split('\n')
quicksort.pop()
x = [row.split(" ")[0] for row in quicksortmedian]
y = [row.split(" ")[1] for row in quicksortmedian]
z = [row.split(" ")[2] for row in quicksortmedian]
a = [row.split(" ")[1] for row in quicksort]
b = [row.split(" ")[2] for row in quicksort]

plt.figure(1)
line1, = plt.plot(x, y, "r", label='quicksortmedian')
line2, = plt.plot(x, a, "b", label='quicksort')
plt.legend(handles=[line1, line2])
plt.title('Comparison of sort algorithms by compares ')
plt.xlabel('Number of elements')
plt.ylabel('Number of compares')
plt.grid(True)

plt.figure(2)
line1, = plt.plot(x, z, "r", label='quicksortmedian')
line2, = plt.plot(x, b, "b", label='quicksort')
plt.legend(handles=[line1, line2])
plt.title('Comparison of sort algorithms by swaps ')
plt.xlabel('Number of elements')
plt.ylabel('Number of swaps')
plt.grid(True)
plt.show()