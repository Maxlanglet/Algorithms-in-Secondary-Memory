import subprocess

# makefile command
def make_compile():
        subprocess.check_call(["make"])
make_compile()

# CHANGE THESE FILES ACCORDING TO YOUR COMPUTER
#list of the files we want to test
files = ["/Users/langletmaxime/Desktop/Database_Systems_Architecture/Algorithms_in_Secondary_Memory/imdb/role_type.csv",
 "/Users/langletmaxime/Desktop/Database_Systems_Architecture/Algorithms_in_Secondary_Memory/imdb/movie_link.csv",
 #"/Users/langletmaxime/Desktop/Database_Systems_Architecture/Algorithms_in_Secondary_Memory/imdb/link_type.csv"]
 #"/Users/langletmaxime/Desktop/Database_Systems_Architecture/Algorithms_in_Secondary_Memory/imdb/info_type.csv"]
 "/Users/langletmaxime/Desktop/Database_Systems_Architecture/Algorithms_in_Secondary_Memory/imdb/complete_cast.csv",
 #"/Users/langletmaxime/Desktop/Database_Systems_Architecture/Algorithms_in_Secondary_Memory/imdb/movie_info_idx.csv"]
 "/Users/langletmaxime/Desktop/Database_Systems_Architecture/Algorithms_in_Secondary_Memory/imdb/aka_name.csv"]
         
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









