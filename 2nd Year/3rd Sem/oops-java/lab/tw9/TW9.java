import java.util.*;

public class TW9 {
	public static void main(String[] args) {
		ArrayList<String> al = new ArrayList<>();
		al.add("Alpha");
		al.add("Beta");
		al.add("Gamma");
		al.add("Delta");
		al.add("Epsilon");
		al.add("Zeta");
		al.add("Eta");

		System.out.println("Original Contents");
		Iterator<String> i = al.iterator();
		while(i.hasNext())
		System.out.print(i.next() + " ");
		System.out.println("\n");

		//to remove Gamma from the list
		i = al.iterator();
		while(i.hasNext()){
			if(i.next().equals("Gamma"))
			i.remove();
		}
		System.out.println("Contents after deletion");
		i=al.iterator();
		while(i.hasNext())
		System.out.print(i.next() + " ");
		System.out.println("\n");

		//to add Gamma back to the list
		ListIterator<String> li = al.listIterator();
		while(li.hasNext()){
			if(li.next().equals("Beta"))
			li.add("Gamma");
		}
		System.out.println("Contents after addition ");
		li = al.listIterator();
		while(li.hasNext())
		System.out.print(li.next() + " ");
		System.out.println("\n");

		//to modify the objects
		String str;
		li = al.listIterator();
		while(li.hasNext()){
			str = li.next();
			switch (str) {
				case "Eta":
				li.set("Omega");
				break;
				case "Zeta":
				li.set("Psi");
				break;
				case "Epsilon":            
				li.set("Chi");
				break;
				case "Delta":
				li.set("Dlt");
				break;
				default:
				break;
			}
		}
		System.out.println("Contents after changes ");
		li= al.listIterator();
		while(li.hasNext())
		System.out.print(li.next() + " ");
		System.out.println("\n");

		//ListIterator to display the backwards
		System.out.println("Modified list backwards ");
		while(li.hasPrevious()){
			System.out.print(li.previous() + " ");
		}
		System.out.println("\n");
		System.out.println("Array elements before sorting ");
		for(String s:al)
		System.out.print(s+" ");
		System.out.println("\n");
		System.out.println("Array elements after sorting in ascending order ");
		Collections.sort(al);
		for(String s:al)
		System.out.print(s+" ");
		System.out.println("\n");
		System.out.println("Array elements after sorting in descending order ");
		Collections.sort(al,Collections.reverseOrder());
		for(String s:al)
		System.out.print(s+" ");
		System.out.println("\n");

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the element to be searched in the list: ");
		String key = sc.nextLine();
		for(String s:al){
			if(s.equals(key)){
				System.out.println("Element found");
				return;
			}
		}
		System.out.println("Element not found");
	}

}
