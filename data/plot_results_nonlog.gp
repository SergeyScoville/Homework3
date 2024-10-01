# gnuplot script to plot Result vs Ti
set datafile separator ","    # CSV file separator

set xlabel "Initial Temperature Values"
set ylabel "Final Distance"


# Optional: Customize the plot appearance
set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 1.5  # Line and point style
set terminal pdfcairo  # Output image size
set output "results_10_5000_by10_R99999.pdf"  # Output file

# Plot the data from the file
plot "results_10_5000_by10_R99999.csv" using 1:2 with linespoints pointtype 7 pointsize 0.3 linecolor rgb "blue" title "Distance of last path"
