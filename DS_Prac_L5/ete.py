from ete3 import Tree
x = Tree("(((D:3,(E:3)F:2)C:2)B:4)A;", format=1)
print(x.get_ascii(show_internal = True))
