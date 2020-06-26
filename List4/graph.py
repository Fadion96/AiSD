import matplotlib.pyplot as plt

with open("tree_stats.txt", "r") as f:
    bst = f.read()


bst = bst.split('\n')
bst.pop()
x = [row.split(" ")[0] for row in bst]
y = [row.split(" ")[1] for row in bst]
z = [row.split(" ")[2] for row in bst]
w = [row.split(" ")[3] for row in bst]


plt.figure(1)
line1, = plt.plot(x, y, "r", label='min')
line2, = plt.plot(x, z, "b", label='avg')
line3, = plt.plot(x, w, "g", label='max')
plt.legend(handles=[line1, line2, line3])
plt.title('Number of compares in BST tree')
plt.xlabel('Number of elements')
plt.ylabel('Number of compares')
plt.grid(True)

plt.show()
