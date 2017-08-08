import java.util.Arrays;
import java.util.List;

public class p273 {
    public class Solution {
        public String numberToWords(int num) {
            if (num == 0) return numbers[0];
            String result = "";
            result = Handle(result, num, numBillion, billion);
            num = num % numBillion;
            result = Handle(result, num, numMillion, million);
            num = num % numMillion;
            result = Handle(result, num, numThousand, thousand);
            num = num % numThousand;
            result = Handle(result, num, 1, "");
            return result.substring(1);
        }

        private String Handle(String result, int num, int threshold, String str) {
            if (num >= threshold) {
                result += toEnglishWords(num / threshold);
                if (!str.isEmpty()) result += " " + str;
            }
            return result;
        }

        private String toEnglishWords(int num) {
            String result = "";
            int h = num / numHundred;
            if (h > 0) {
                result += " " + numbers[h] + " " + hundred;
            }
            num = num % numHundred;
            if (num > 0) {
                if (num <= 19) {
                    result += " " + numbers[num];
                } else {
                    int t = num / 10;
                    num %= 10;
                    result += " " + tens[t];
                    if (num != 0) result += " " + numbers[num];
                }
            }
            return result;
        }

        private String[] numbers = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        private String[] tens = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        private String hundred = "Hundred";
        private String thousand = "Thousand";
        private String million = "Million";
        private String billion = "Billion";

        private int numHundred = 100;
        private int numThousand = 1000;
        private int numMillion = 1000000;
        private int numBillion = 1000000000;
    }
}
