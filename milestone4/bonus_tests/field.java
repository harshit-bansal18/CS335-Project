public class Student {
    int id=200597;
    int[] grades = new int[5];

    public long calculateAverage() {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += grades[i];
        }
        return (long) sum / 5;
    }

    public void assignGrades() {
        for (int i = 0; i < 5; i++) {
            grades[i] = 10*(i+1);
            System.out.println(grades[i]);
        }
    }

    public void run() {
        System.out.println(1000001);    //ID
        System.out.println(id);
        System.out.println(2000002);    //Grades
        assignGrades();
        for (int i = 0; i < 5; i++) {
            System.out.println(grades[i]);
        }
        System.out.println(3000003);    //Average
        System.out.println(calculateAverage());
    }
}

public class arrayasfield {
    public static void main(String[] args) {
        Student s = new Student();
        s.run();
    }
}