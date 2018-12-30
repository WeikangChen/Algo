package lineMaximalPoints;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;

public class Application {

	static int count = 0;
	static int number = 1;
	static ArrayList<Line> lines = new ArrayList<>();
	static HashSet<Point> pts = new HashSet<>();

	public static void main(String[] args) throws FileNotFoundException, IOException {
		File file = new File("C:/points.csv");
		// enter the path of the file here
		try (BufferedReader br = new BufferedReader(new FileReader(file))) {
			// try with resource so that the file will auto-close, avoiding
			// trunks of exceptions handling
			String fileLine;
			String[] fileParts;

			while ((fileLine = br.readLine()) != null) {

				ArrayList<Double> filePartsNumber = new ArrayList<>();
				if (fileLine.trim().length() > 0) {// check if it is an empty
													// row
					fileParts = fileLine.split(",");// split the numbers
					for (int i = 0; i < fileParts.length; i++) {

						filePartsNumber.add(Double.parseDouble(fileParts[i]));
					}
					Point pt = new Point(filePartsNumber);
					if (pts.isEmpty()) {// cannot form a line with one point
						pts.add(pt);

					} else if (!(pts.contains(pt))) {
						HashSet<Point> tempPts = new HashSet<>();
						HashSet<Point> tempPtsComp = new HashSet<>();
						pts.add(pt);
						for (Line line : lines) {
							if (line.isOnTheLine(pt)) {
								line.getElements().add(pt);
								// add the point to the line
								for (int j = 0; j < line.getElements().size(); j++) {
									tempPts.add(line.getElements().get(j));
								}
							}
						}

						for (Point pt0 : pts) {
							if (!(tempPts.contains(pt0))) {
								tempPtsComp.add(pt0);
							}
						}
						// find the complement set of tempPts

						tempPtsComp.remove(pt);

						for (Point tempPt : tempPtsComp) {
							// add new lines
							ArrayList<Point> pts1 = new ArrayList<>();
							pts1.add(pt);
							pts1.add(tempPt);
							lines.add(new Line(pts1));

						}

					}

				}

			}

		}

		for (Line line : lines) {
			if (line.getElements().size() >= count) {
				count = line.getElements().size();
			}
		} // find the number of maximal points on a line

		for (Line line : lines) {
			if (line.getElements().size() == count) {
				System.out.println("Line " + number);
				Line.printLine(line);
				number++;
			}
		} // print all the lines containing maximal number of points

	}
}