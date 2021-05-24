package E;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String s1 = input.nextLine();
        String s2 = input.nextLine();
        int left = 0;
        int s1Length = s1.length();
        int s2Length = s2.length();
        int right = Math.min(s1Length,s2Length);
        while(left <= right){
            boolean flag = true;
            int mid = (left + right)>>1;
            for(int i = 0;i <= s1Length - mid;i++){
                if(s2.contains(s1.substring(i,i+mid))){
                    left = mid+1;
                    flag = false;
                    break;
                }
            }
            if(flag)
                right = mid - 1;
        }
        System.out.println(right);
    }
}
