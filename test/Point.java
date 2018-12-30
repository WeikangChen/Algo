package lineMaximalPoints;

import java.util.ArrayList;

public class Point {
	private ArrayList<Double> coordinates;

	public Point(ArrayList<Double> coordinates) {
		this.coordinates = coordinates;
	}

	public ArrayList<Double> getCoordinates() {
		return coordinates;
	}

	@Override
	public int hashCode() {
		String temp = "";
		for (int i = 0; i < coordinates.size(); i++) {
			temp += String.valueOf(coordinates.get(i));

		}
		return temp.hashCode();
	}

	@Override
	public boolean equals(Object arg0) {
		Point pt = (Point) arg0;
		for (int i = 0; i < pt.coordinates.size(); i++) {
			if (!this.coordinates.get(i).equals(pt.coordinates.get(i))) {
				return false;
			}
		}

		return true;
	}

	public static void printPoint(Point pt) {
		// print a point
		for (int i = 0; i < pt.coordinates.size() - 1; i++) {
			System.out.print(pt.coordinates.get(i) + ", ");
		}
		System.out.println(pt.coordinates.get(pt.coordinates.size() - 1));

	}
}
