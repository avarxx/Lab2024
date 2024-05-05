import matplotlib.pyplot as plt

def plot_histogram(filename, title):
    hashes = []
    collisions = []
    with open(filename, 'r') as f:
        for line in f:
            hash_val, collision_count = map(int, line.split())
            hashes.append(hash_val)
            collisions.append(collision_count)

    plt.bar(hashes, collisions)
    plt.title(title)
    plt.xlabel('Хэш-значение')
    plt.ylabel('Число коллизий')
    plt.show()

def main():
  plot_histogram('collisions_remainder.txt', 'Остаток от деления')
  plot_histogram('collisions_bit.txt', 'Битовое представление')
  plot_histogram('collisions_multiplication.txt', 'Метод умножения')

if __name__ == "__main__":
    main()