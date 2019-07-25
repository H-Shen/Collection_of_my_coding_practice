import java.util.*;
import java.math.BigDecimal;

class Student{
	private int id;
	private String fname;
	private double cgpa;
	public Student(int id, String fname, double cgpa) {
		super();
		this.id = id;
		this.fname = fname;
		this.cgpa = cgpa;
	}
	public int getId() {
		return id;
	}
	public String getFname() {
		return fname;
	}
	public double getCgpa() {
		return cgpa;
	}
}

//Complete the code
public class Solution
{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int testCases = Integer.parseInt(in.nextLine());

		List<Student> studentList = new ArrayList<Student>();
		while(testCases>0){
			int id = in.nextInt();
			String fname = in.next();
			double cgpa = in.nextDouble();

			Student st = new Student(id, fname, cgpa);
			studentList.add(st);

			testCases--;
		}
        studentList.sort((o1, o2) -> {
            BigDecimal cgpa1 = new BigDecimal(o1.getCgpa());
            BigDecimal cgpa2 = new BigDecimal(o2.getCgpa());
            if (cgpa1.compareTo(cgpa2) == 0) {
                String fname1 = o1.getFname();
                String fname2 = o2.getFname();
                if (fname1.compareTo(fname2) == 0) {
                    int id1 = o1.getId();
                    int id2 = o2.getId();
                    if (id1 == id2) {
                        return 0;
                    } else if (id1 > id2) {
                        return 1;
                    }
                    return -1;
                } else if (fname1.compareTo(fname2) > 0) {
                    return 1;
                }
                return -1;
            } else if (cgpa1.compareTo(cgpa2) > 0) {
                return -1;
            }
            return 1;
        });
      	for(Student st: studentList){
			System.out.println(st.getFname());
		}
	}
}



