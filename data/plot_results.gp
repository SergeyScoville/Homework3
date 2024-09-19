# gnuplot script to plot Result vs Ti

set datafile separator ","    # CSV file separator
set title "Simulated Annealing Results"
set xlabel "Temperature (Ti)"
set ylabel "Result"
set grid

# Optional: Customize the plot appearance
set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 1.5  # Line and point style
set terminal pngcairo size 1280,960  # Output image size
set output "results_plot.png"  # Output file

# Plot the data from the file
plot "../data/results.csv" using 1:2 with linespoints linestyle 1 title "Result vs Ti"

