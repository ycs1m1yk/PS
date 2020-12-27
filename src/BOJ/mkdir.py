# %%
import os

cwd = os.getcwd()
print(cwd)

# %%
os.chdir(cwd)
os.mkdir('2nd')
# %%
path = os.path.join(cwd, '2nd')
os.chdir(path)

for i in range(19):
    os.mkdir('{0}'.format((i+1)*1000))
# %%
