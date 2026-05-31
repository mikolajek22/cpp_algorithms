import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv("data/sorting_results.csv")

algorithms = df["algorithm"].unique()
colors = {
    "bubble":    "red",
    "insertion": "orange",
    "selection": "blue",
    "merge":     "green",
}

fig, axes = plt.subplots(1, 2, figsize=(14, 6))

# Compare all algs
ax1 = axes[0]
for alg in algorithms:
    subset = df[df["algorithm"] == alg]
    ax1.plot(subset["n"], subset["time_us"],
             marker="o", label=alg, color=colors.get(alg))

ax1.set_title("Alghorithms")
ax1.set_xlabel("n")
ax1.set_ylabel("time [µs]")
ax1.legend()
ax1.grid(True)

# Display Merge sort
ax2 = axes[1]
merge = df[df["algorithm"] == "merge"]
ax2.plot(merge["n"], merge["time_us"],
         marker="o", color="green", label="merge")

# reference nlog(n)
x = np.array(merge["n"])
nlogn = x * np.log2(x)
nlogn = nlogn / nlogn.max() * merge["time_us"].max()
ax2.plot(x, nlogn, linestyle="--", color="gray", label="n log n (ref)")

ax2.set_title("Merge sort vs n log n")
ax2.set_xlabel("n")
ax2.set_ylabel("time [µs]")
ax2.legend()
ax2.grid(True)

plt.tight_layout()
plt.savefig("data/benchmark.png", dpi=150)
plt.show()