import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.io.FileWriter;
import java.util.Set;
public class Main 
{
/* for implementation using arraylist
	private static List<Object> user_id = new ArrayList<>();
	private static List<Object> movie = new ArrayList<>();
	private static List<Object> rating = new ArrayList<>();*/
	private static HashMap<Integer, HashMap<Integer, Float>> ratings = new HashMap<Integer, HashMap<Integer, Float>>();
	private static Set user_id = new HashSet();
	private static Set movie = new HashSet();
	private static int count=0;


	public static void main(String[] args) throws IOException
	{
		Main obj = new Main();
		//obj.run(); // for implementation using arraylist
		obj.store_in_hashmap();
		
		obj.writeresults();
	}
	public void store_in_hashmap()
	{
		//this code reads csv file and stores data in three different lists
		//using reference from here : http://www.mkyong.com/java/how-to-read-and-parse-csv-file-in-java/
		String cvsFile = "/Users/rahulmakwana/Desktop/Documents/Spring 2015/CS5369 Recommender Systems/Assignment 1/ratings.csv";
		BufferedReader br = null;
		String line = "";
		String cvsSplitBy= ",";
		try
		{
			br = new BufferedReader(new FileReader(cvsFile));
			while((line = br.readLine()) != null)
			{
				String[] country = line.split(cvsSplitBy);
                ratings.put(Integer.parseInt(country[1]), new HashMap<Integer, Float>());
                ratings.get(Integer.parseInt(country[1])).put(Integer.parseInt(country[0]), Float.parseFloat(country[2]));
                if (!user_id.contains(Integer.parseInt(country[0])))
                    user_id.add(Integer.parseInt(country[0]));
                if (!movie.contains(Integer.parseInt(country[1])))
                    movie.add(Integer.parseInt(country[1]));
                count++;
			}
/*			for(int i=0;i<count/2;i++) //to test if data stored in lists or not			
			{
				System.out.println("user="+user_id.get(i) + ", movie"+movie.get(i)+", rating="+rating.get(i));
			}
*/
		}
		catch(FileNotFoundException e)
		{
			e.printStackTrace();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
		finally
		{
			if(br != null)
			{
				try
				{
					br.close();
				}
				catch(IOException e)
				{
					e.printStackTrace();
				}
			}
		}
		System.out.println("Stored in Hashmap");	
		compute_mean();
	}
	private static void compute_mean()
	{
		//to find mean and damped mean 
		float movieMeanRating = 0;
		float movieDampedMeanRating = 0;
		Map<Integer, Float> meanValue = new HashMap<Integer, Float>();// we'll store final mean value of movies in this var
		Map<Integer, Float> dampedmeanValue = new HashMap<Integer, Float>();// we'll store final damped mean value of movies in this var
		for(Map.Entry<Integer, HashMap<Integer,Float>> movieMap : ratings.entrySet())
		{
			int index = movieMap.getKey();
			Collection<Float>  userRatings = movieMap.getValue().values();
			//float count1=userRatings.size();
			/*for(int i=0;i<count1;i++)
			{
				movieMeanRating = movieMeanRating + userRatings.
			}*/
			for(Float iterate : userRatings)
			{
				movieMeanRating = movieMeanRating + iterate; //iterates for each entry of movie and computes rating value, sums it
			}
			float count1=userRatings.size();
			float temp = movieMeanRating;
			// finally we divide the sum by number of movie counts
			movieMeanRating = movieMeanRating / count1;
			movieMeanRating = movieMeanRating / 100 ;
			//damped mean formula => dampedmean = (sum of value + (sum of value / number of values) * 5 ) / (number of values + 5)
			movieDampedMeanRating = (temp+(temp/count1)*5) / (count1+5);
			movieDampedMeanRating = movieDampedMeanRating / 100;
			meanValue.put(index, movieMeanRating);
			dampedmeanValue.put(index,movieDampedMeanRating);
			count1 = 0;
		}
		List<Map.Entry<Integer, Float>> listOfMeanValues = new ArrayList<Map.Entry<Integer, Float>>(meanValue.entrySet());
		List<Map.Entry<Integer, Float>> listOfDampedMeanValues = new ArrayList<Map.Entry<Integer, Float>>(dampedmeanValue.entrySet());
		display(listOfMeanValues,listOfDampedMeanValues);
	}
	public static void display(List<Map.Entry<Integer, Float>> list_of_means,List<Map.Entry<Integer, Float>> list_of_damped_mean)  
	{
		// Task 1
      //  Collections.sort(list_of_means, new Main.myCustomCompare<Integer,Float>());//sorting list
        int index =0;
        String file_name = "/Users/rahulmakwana/Desktop/Documents/Spring 2015/CS5369 Recommender Systems/Assignment 1/mean_result.txt";
		BufferedWriter writer=null;
			try
			{
				File file = new File(file_name);
				writer = new BufferedWriter(new FileWriter(file));
				writer.write("TOP MOVIES BY MEAN \n");
				writer.write(" MovieID    Mean\n");
				for(Map.Entry<Integer, Float> mov_ratings : list_of_means)
				{
					int key = mov_ratings.getKey();
					float value = mov_ratings.getValue();
					writer.write(" " + key + "   " + value + "\n");
					index++;
					if(index==10)
					{
						break;
					}
				}
			}
			catch(Exception e)
			{
				e.printStackTrace();
			}
			finally
			{
				try
				{
					writer.close();
				}
				catch(Exception e)
				{
				}
			}
        //Task 2
        index=0;

        String file_name_damped_mean = "/Users/rahulmakwana/Desktop/Documents/Spring 2015/CS5369 Recommender Systems/Assignment 1/damped_mean_result.txt";
		writer=null;
			try
			{
				File file = new File(file_name_damped_mean);
				writer = new BufferedWriter(new FileWriter(file));
				writer.write("TOP MOVIES BY DAMPED MEAN \n");
				writer.write(" MovieID    Mean\n");
				for(Map.Entry<Integer, Float> mov_ratings : list_of_damped_mean)
				{
					int key = mov_ratings.getKey();
					float value = mov_ratings.getValue();
					writer.write(" " + key + "   " + value + "\n");
					index++;
					if(index==10)
					{
						break;
					}
				}
			}
			catch(Exception e)
			{
				e.printStackTrace();
			}
			finally
			{
				try
				{
					writer.close();
				}
				catch(Exception e)
				{
				}
			}
	}
/*	public void run() 
	{
		//this code reads csv file and stores data in three different lists
		String cvsFile = "/Users/rahulmakwana/Desktop/Documents/Spring 2015/CS5369 Recommender Systems/Assignment 1/ratings.csv";
		BufferedReader br = null;
		String line = "";
		String cvsSplitBy= ",";
		try
		{
			br = new BufferedReader(new FileReader(cvsFile));
			while((line = br.readLine()) != null)
			{
				String[] country = line.split(cvsSplitBy);
				user_id.add(country[0]);//stores in user list values from csv file
				movie.add(country[1]);//stores in movie list values from csv file
				rating.add(country[2]);//stores in rating list values from csv file
				count++;
			}
/*			for(int i=0;i<count/2;i++) //to test if data stored in lists or not			
			{
				System.out.println("user="+user_id.get(i) + ", movie"+movie.get(i)+", rating="+rating.get(i));
			}
*/
/*		}
		catch(FileNotFoundException e)
		{
			e.printStackTrace();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
		finally
		{
			if(br != null)
			{
				try
				{
					br.close();
				}
				catch(IOException e)
				{
					e.printStackTrace();
				}
			}
		}
		System.out.println("Stored in Lists");
	}
	*/
	private static void simpleMetric()
	{
		//code for task 3 and 4
	}
	public void writeresults()
	{
		String file_name = "/Users/rahulmakwana/Desktop/Documents/Spring 2015/CS5369 Recommender Systems/Assignment 1/results.txt";
		BufferedWriter writer=null;
		
		try
		{
			File file = new File(file_name);
			writer = new BufferedWriter(new FileWriter(file));
			
			writer.write("TOP MOVIES BY MEAN \n");
			
			for(int i=0;i<count;i++ )
			{
//				writer.write("user = "+user_id.get(i)+"\n");//for arraylist
               // ratings.get(Integer.parseInt(country[0])).put(Integer.parseInt(country[1]), Float.parseFloat(country[2]));
                //writer.write("user = "+ratings.entrySet()+"\n");
			}
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			try
			{
				writer.close();
			}
			catch(Exception e)
			{
				
			}
		}

	}
	//in order to sort HashMap elements we need to implement a comparator class being extended by a customised dummy class i.e. myCustomCompare
	//reference link: http://snipplr.com/view/2789/sorting-map-keys-by-comparing-its-values
    class myCustomCompare<K extends Comparable<? super K>,V extends Comparable<? super V>>
    implements Comparator<Map.Entry<K, V>> 
    {
    	public int compare(Map.Entry<K, V> val1, Map.Entry<K, V> val2) 
    	{
    		int temp = val2.getValue().compareTo(val1.getValue());
    		if (temp != 0) 
    		{
    			return temp;
    		} 
    		else 
    		{
    			return val1.getKey().compareTo(val2.getKey());
    		}
    	}	
}
	
}