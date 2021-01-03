import subprocess

# makefile command
def make_compile():
        subprocess.check_call(["make"])
make_compile()

# CHANGE THESE FILES ACCORDING TO YOUR COMPUTER
#list of the files we want to test
files = ["./role_type.csv",
 "./movie_link.csv",
 #"./link_type.csv"]
 #"./info_type.csv"]
 "./complete_cast.csv",
 #"./movie_info_idx.csv"]
 "./aka_name.csv"]
         
#list of the buffer sizes we want to test

#buffersizes = ["10", "50", "1000", "10000", "100000", "1000000"]#randjump reading 
#buffersizes = ["1000", "10000", "100000", "1000000"]#mergesort
#buffersizes = ["5","10","15","20"]#mergesort
buffersizes = ["10","50","1000", "4096", "8192", "12288","40960", "409600", "4096000"]#rrmerge and sequential reading

#for every file, we run the code for every buffer size
results = open("output_results.txt", "w")
for filename in files:
    print(filename)
    for buffersize in buffersizes:
        proc = subprocess.call(["./main",filename,buffersize], stdout=results)









