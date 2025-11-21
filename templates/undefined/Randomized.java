package undefined;

import java.util.Random;

public class Randomized {
    public void shuffle(int[] array) {
        Random random = new Random();
        for (int i = array.length - 1; i > 0; i--) {
            int randomIdx = random.nextInt(i + 1);
            int tmp = array[randomIdx];
            array[randomIdx] = array[i];
            array[i] = tmp;
        }
    }
}
