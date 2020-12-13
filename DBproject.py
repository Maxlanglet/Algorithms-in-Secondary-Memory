import os
import subprocess
from time import sleep

# A CHANGER : le path de ton code
# makefile command
def make_compile():
        subprocess.check_call(["make"])
#subprocess.check_call(["make"], cwd="../../ads/main/name_of_the_prog")
make_compile()

# A CHANGER : le path de tes fichiers
#list of the files we want to test
files = ["aka_names.csv", "role_type.csv","movie_link.csv","more_info_idx.csv"]
         
#list of the buffer sizes we want to test
buffersizes = [10, 50, 1000, 4096, 8192, 12288,40960,409600, 4096000]

#for every file, we run the code for every buffer size
results = open("output_results.txt", "w")
for filename in files:
    print filename
    for buffersize in buffersizes:
        proc = subprocess.call(["./main",filename,buffersize], stdout=results)
        proc.wait()








