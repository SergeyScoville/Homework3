set terminal pngcairo size 800,600
set output 'histogram_N_1000.png'

set title "Histogram of Monte Carlo Volume Estimates (N = 1000)"
set xlabel "Volume"
set ylabel "Frequency"

# Adjust bin size as needed
bin_width = 0.01
bin(x, width) = width * floor(x/width) + bin_width/2.0

# Plot histogram
plot 'volume_N_1000.txt' using (bin($1, bin_width)):(1.0) smooth freq with boxes lc rgb "blue" title "N = 1000"

