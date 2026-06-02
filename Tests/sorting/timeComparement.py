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
    "quick":     "pink",
    "heap":      "yellow",
}

BG      = "#000000"  # czarne tło wykresu i figury
GRID    = "#2a2a2a"  # ciemnoszara siatka
TEXT    = "#cccccc"  # jasnoszare opisy, tytuły, etykiety osi, legenda
SPINE   = "#444444"  # obramowanie osi

def style_ax(ax):
    ax.set_facecolor(BG)
    ax.grid(True, color=GRID, linewidth=0.8)
    ax.tick_params(colors=TEXT)
    ax.xaxis.label.set_color(TEXT)
    ax.yaxis.label.set_color(TEXT)
    ax.title.set_color(TEXT)
    for spine in ax.spines.values():
        spine.set_edgecolor(SPINE)
    legend = ax.get_legend()
    if legend:
        legend.get_frame().set_facecolor("#111111")
        legend.get_frame().set_edgecolor(SPINE)
        for text in legend.get_texts():
            text.set_color(TEXT)

fig, axes = plt.subplots(1, 2, figsize=(14, 6))
fig.patch.set_facecolor(BG)

# ── wykres 1: wszystkie algorytmy ────────────────────────────
ax1 = axes[0]
for alg in algorithms:
    subset = df[df["algorithm"] == alg]
    ax1.plot(subset["n"], subset["time_us"],
             marker="o", label=alg, color=colors.get(alg))
ax1.set_title("Wszystkie algorytmy")
ax1.set_xlabel("n")
ax1.set_ylabel("czas [µs]")
ax1.legend()
style_ax(ax1)

# ── wykres 2: O(n log n) + krzywa referencyjna ───────────────
ax2 = axes[1]
algorithms_nlogn = df[df["algorithm"].isin(["merge", "quick", "heap"])]
for alg in algorithms_nlogn["algorithm"].unique():
    subset = df[df["algorithm"] == alg]
    ax2.plot(subset["n"], subset["time_us"],
             marker="o", label=alg, color=colors.get(alg))

ref = algorithms_nlogn[algorithms_nlogn["algorithm"] == "merge"]
x = np.array(ref["n"])
nlogn = x * np.log2(x)
nlogn = nlogn / nlogn.max() * ref["time_us"].max()
ax2.plot(x, nlogn, linestyle="--", color="gray", label="n log n (ref)")

ax2.set_title("O(n log n) — merge / quick / heap vs. n log n")
ax2.set_xlabel("n")
ax2.set_ylabel("czas [µs]")
ax2.legend()
style_ax(ax2)

plt.tight_layout()
plt.savefig("data/benchmark.png", dpi=150, facecolor=BG)
plt.show()