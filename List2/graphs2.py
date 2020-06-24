import matplotlib.pyplot as plt

with open("insert_stat.txt", "r") as f:
    insert = f.read()

with open("merge_stat.txt", "r") as f:
    merge = f.read()

with open("quick_stat.txt", "r") as f:
    quick = f.read()

with open("quickinsert_stat.txt", "r") as f:
    quickinsert = f.read()

with open("mergeinsert_stat.txt", "r") as f:
    mergeinsert = f.read()

with open("dualpivotquick_stat.txt", "r") as f:
    dualpivot = f.read()

insert = insert.split('\n')
merge = merge.split('\n')
quick = quick.split('\n')
quickinsert = quickinsert.split('\n')
mergeinsert = mergeinsert.split('\n')
dualpivot = dualpivot.split('\n')

insert.pop()
merge.pop()
quick.pop()
quickinsert.pop()
mergeinsert.pop()
dualpivot.pop()

x = [row.split(" ")[0] for row in merge]
a = [row.split(" ")[2] for row in merge]
b = [row.split(" ")[2] for row in quick]
c = [row.split(" ")[2] for row in insert]
d = [row.split(" ")[2] for row in quickinsert]
e = [row.split(" ")[2] for row in mergeinsert]
f = [row.split(" ")[2] for row in dualpivot]

line1, = plt.plot(x, a, "r", label='mergeSort')
line2, = plt.plot(x, b, "g", label='quickSort')
line3, = plt.plot(x, c, "b", label='insertSort')
line4, = plt.plot(x, d, "m", label='quickinsert')
line5, = plt.plot(x, e, "r--", label='mergeinsert')
line6, = plt.plot(x, f, "y", label='dualpivot')

plt.legend(handles=[line1, line2, line3, line4, line5, line6])
plt.title('Comparison of sort algorithms by swaps')
plt.xlabel('Number of elements')
plt.ylabel('Number of swaps')
plt.grid(True)
plt.ylim(ymax=2000000, ymin=0)
plt.show()
