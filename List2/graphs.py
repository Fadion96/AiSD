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
a = [row.split(" ")[1] for row in merge]
b = [row.split(" ")[1] for row in quick]
c = [row.split(" ")[1] for row in insert]
d = [row.split(" ")[1] for row in quickinsert]
e = [row.split(" ")[1] for row in mergeinsert]
f = [row.split(" ")[1] for row in dualpivot]

plt.plot(x, a, "r", label='mergeSort')
plt.plot(x, b, "g", label='quickSort')
plt.plot(x, c, "b", label='insertSort')
plt.plot(x, d, "m", label='quickinsert')
plt.plot(x, e, "r--", label='mergeinsert')
plt.plot(x, f, "y", label='dualpivot')
plt.legend()
plt.title('Comparison of sort algorithms by compares')
plt.xlabel('Number of elements')
plt.ylabel('Number of compares')
plt.grid(True)
plt.ylim(ymax=2500000, ymin=100)
plt.show()
