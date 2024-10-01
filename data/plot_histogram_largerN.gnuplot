set terminal pdfcairo
set output 'histogram_N_1000_M_10000.pdf'

set xlabel "Volume"
set ylabel "Frequency"

# Adjust bin size as needed
bin_width = 0.001
bin(x, width) = width * floor(x/width) + bin_width/2.0

# Plot histogram
plot 'result_MonteCarlo_M_10000_N_1000.txt' using (bin($1, bin_width)):(1.0) smooth freq with boxes lc rgb "blue" title "N = 1000"

