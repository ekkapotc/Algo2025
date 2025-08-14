# Set output image format
set terminal pngcairo size 800,600 enhanced font 'Arial,12'
set output 'performance_plot.png'

# Title and axis labels
set title "Algorithm's Running Times"
set xlabel "Problem Size"
set ylabel "Time (ms)"

# Enable grid
set grid

# Plot the data file
plot 'output_O0.out' using 1:2 with linespoints title 'Execution Time with -O0',\
     'output_O3.out' using 1:2 with linespoints title 'Execution Time with -O3'
