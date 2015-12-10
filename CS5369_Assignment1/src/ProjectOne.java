import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.*;

/**
 * author  Tajinder
 * Dated on 2/2/2015.
 */
public class ProjectOne {

    private static String csvFileName;

    private static HashMap<Integer, HashMap<Integer, Float>> map = new HashMap<Integer, HashMap<Integer, Float>>();
    private static Set users = new HashSet();
    private static Set items = new HashSet();

    public static void main(String[] args) throws FileNotFoundException 
    {

        try {
            csvFileName = "/Users/rahulmakwana/Desktop/Documents/Spring 2015/CS5369 Recommender Systems/Assignment 1/ratings.csv";
            String line = null;
            BufferedReader br = new BufferedReader(new FileReader(csvFileName));

            try {
                while ((line = br.readLine()) != null) {
                    String str[] = line.split(",");
                    //    System.out.println(str.length);
                    for (int i = 0; i < str.length; i++) {
                        if(!map.containsKey(Integer.parseInt(str[1])))
                            map.put(Integer.parseInt(str[1]), new HashMap<Integer, Float>());

                        map.get(Integer.parseInt(str[1])).put(Integer.parseInt(str[0]), Float.parseFloat(str[2]));

                        if (!users.contains(Integer.parseInt(str[0])))
                            users.add(Integer.parseInt(str[0]));
                        if (!items.contains(Integer.parseInt(str[1])))
                            items.add(Integer.parseInt(str[1]));
                    }
                }
            } finally {
                br.close();
            }

            scoreBySimple();
            scoreByAdvancedMetric();
            mean();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

   // private static void mean(Set users, Set items, HashMap<Integer, HashMap<Integer, Float>> map) {
      private static void mean() {
        int countUi = 0;
        float itemMeanRating = 0;
        float itemDampMeanRating = 0;
        Map<Integer, Float> meanResult = new HashMap<Integer, Float>();
        Map<Integer, Float> dampMeanResult = new HashMap<Integer, Float>();

             for(Map.Entry<Integer, HashMap<Integer,Float>> itemMap : map.entrySet()) 
             {
              int item = itemMap.getKey();
              Collection<Float> userRatings =    itemMap.getValue().values();
              for (Float rating:userRatings)
              {
                 itemMeanRating += rating;
              }
              countUi=userRatings.size();
              itemDampMeanRating = (itemMeanRating+(itemMeanRating/countUi)*5) / (countUi+5);
              itemMeanRating = itemMeanRating / countUi;
              DecimalFormat df = new DecimalFormat("#.###");
              itemMeanRating = Float.valueOf(df.format(itemMeanRating));
              meanResult.put(item, itemMeanRating);

              itemDampMeanRating = Float.valueOf(df.format(itemDampMeanRating));
              dampMeanResult.put(item, itemDampMeanRating);
              countUi = 0;
            }

       //  meanResult = sortByValue(meanResult);
        List<Map.Entry<Integer, Float>> listM = new ArrayList<Map.Entry<Integer, Float>>(meanResult.entrySet());
        Collections.sort(listM, new ValueThanKeyComparator<Integer, Float>());
        int indexM =0;
        System.out.println("\nTHE TOP TEN MOVIES BY  MEAN METHOD:\n");

        for (Map.Entry<Integer, Float> itemRatings : listM) {
            int key = itemRatings.getKey();
            float value = itemRatings.getValue();
            System.out.println("Item:" + key + "    Mean Rating:" + value);
            indexM++;
            if(indexM==10)
            {
                break;
            }
        }
          List<Map.Entry<Integer, Float>> listDM = new ArrayList<Map.Entry<Integer, Float>>(dampMeanResult.entrySet());
          Collections.sort(listDM, new ValueThanKeyComparator<Integer, Float>());
          int indexDM =0;
          System.out.println("\nTHE TOP TEN MOVIES BY DAMPED MEAN METHOD:\n");

          for (Map.Entry<Integer, Float> itemRatings : listDM) {
              int key = itemRatings.getKey();
              float value = itemRatings.getValue();
              System.out.println("Item:" + key + "    Mean Rating:" + value);
              indexDM++;
              if(indexDM==10)
              {
                  break;
              }
          }
    //    System.out.println("Mean Results: " + meanResult);

/*commented*/
        //sort in increasing order
        //  meanResult = sortByValue(meanResult);
//        for (Map.Entry<Integer, Float> entry : meanResult.entrySet()) {
//            Integer key = entry.getKey();
//            Float value = entry.getValue();
//            System.out.println("Item:" + key + " Rating:" + value);
//        }

//    public static <K, V extends Comparable<? super V>> Map<K, V>
//    sortByValue( Map<K, V> map )
//    {
//        List<Map.Entry<K, V>> list =
//                new LinkedList<Map.Entry<K, V>>( map.entrySet() );
//        Collections.sort( list, new Comparator<Map.Entry<K, V>>()
//        {
//            public int compare( Map.Entry<K, V> o1, Map.Entry<K, V> o2 )
//            {
//                return (o1.getValue()).compareTo( o2.getValue() );
//            }
//        } );
//
//        Map<K, V> result = new LinkedHashMap<K, V>();

//        for (Map.Entry<K, V> entry : list)
//        {
//            result.put( entry.getKey(), entry.getValue() );
//        }
//        return result;
//    }
//}


    }
    private static void scoreBySimple() {
        int countUi = 0;// number of users rated item i
        int countUsersRSW;
        float itemScore = 0;
        Map<Integer, Float> scoresMap = new HashMap<Integer, Float>();

        countUsersRSW  = map.get(11).size();
        for(Map.Entry<Integer, HashMap<Integer,Float>> itemMap : map.entrySet()) {
            int item = itemMap.getKey();
            for(Map.Entry<Integer,Float> userRating : itemMap.getValue().entrySet()) {
                int user = userRating.getKey();
                if(map.get(11).containsKey(user))
                {
                    countUi++;

                }
            }
            itemScore =  (float) countUi/(float)countUsersRSW;
            DecimalFormat df = new DecimalFormat("#.###");
            itemScore = Float.valueOf(df.format(itemScore));
            if(item!=11)
            scoresMap.put(item, itemScore);

            countUi = 0;//reset
        }

        //  meanResult = sortByValue(meanResult);
        List<Map.Entry<Integer, Float>> listM = new ArrayList<Map.Entry<Integer, Float>>(scoresMap.entrySet());
        Collections.sort(listM, new ValueThanKeyComparator<Integer, Float>());
        int indexM =0;
        System.out.println("\nTHE 10 MOVIES MOST SIMILAR TO MOVIE 11 (STAR WARS) USING THE SIMPLE METRIC:\n");

        for (Map.Entry<Integer, Float> itemRatings : listM) {
            int key = itemRatings.getKey();
            float value = itemRatings.getValue();
            System.out.println("Item:" + key + "    Mean Rating:" + value);
            indexM++;
            if(indexM==10)
            {
                break;
            }
        }

//        List<Map.Entry<Integer, Float>> listDM = new ArrayList<Map.Entry<Integer, Float>>(dampMeanResult.entrySet());
//        Collections.sort(listDM, new ValueThenKeyComparator<Integer, Float>());
//        int indexDM =0;
//        System.out.println("\nTHE TOP TEN MOVIES BY DAMPED MEAN METHOD:\n");
//
//        for (Map.Entry<Integer, Float> itemRatings : listDM) {
//            int key = itemRatings.getKey();
//            float value = itemRatings.getValue();
//            System.out.println("Item:" + key + "    Mean Rating:" + value);
//            indexDM++;
//            if(indexDM==10)
//            {
//                break;
//            }
//        }


    }
    private static void scoreByAdvancedMetric( ) {
        int countUi = 0;// number of users rated item i
        int countUNotI = 0;// number of users rated item i
        int countUsersNotRatedB;
        int countUsersRatedB;
        float itemScore = 0;
        float numerator = 0;
        float denominator = 0;
        Map<Integer, Float> scoresMap = new HashMap<Integer, Float>();

        countUsersRatedB  = map.get(414).size();
        countUsersNotRatedB  = users.size()-countUsersRatedB;
       // System.out.println(countUsersRatedB+"::"+countUsersNotRatedB);
        for(Map.Entry<Integer, HashMap<Integer,Float>> itemMap : map.entrySet()) {
            int item = itemMap.getKey();
            for(Map.Entry<Integer,Float> userRating : itemMap.getValue().entrySet()) {
                int user = userRating.getKey();
                if(map.get(414).containsKey(user)) {
                    countUi++;
                } else {
                        countUNotI++;
                }
            }
            if(item!=414) {
                // System.out.print(scoresMapBySimple);
               // System.out.println("ITem:" + item);
                numerator = (float) countUi / (float) countUsersRatedB;
               // System.out.println("N:" + numerator);

                denominator = (float) countUNotI / (float) countUsersNotRatedB;
               // System.out.println("D:" + denominator);

                itemScore = numerator / denominator;
              //  System.out.println(itemScore);
                DecimalFormat df = new DecimalFormat("#.###");
                itemScore = Float.valueOf(df.format(itemScore));

                scoresMap.put(item, itemScore);
            }
            countUi = 0;//reset
            countUNotI = 0;
        }

        //  meanResult = sortByValue(meanResult);
        List<Map.Entry<Integer, Float>> listM = new ArrayList<Map.Entry<Integer, Float>>(scoresMap.entrySet());
        Collections.sort(listM, new ValueThanKeyComparator<Integer, Float>());
        int indexM =0;
        System.out.println("\nTHE 10 MOVIES MOST SIMILAR TO MOVIE 414 (BATMAN) USING THE ADVANCED METRIC:\n");

        for (Map.Entry<Integer, Float> itemRatings : listM) {
            int key = itemRatings.getKey();
            float value = itemRatings.getValue();
            System.out.println("Item:" + key + "    Mean Rating:" + value);
            indexM++;
            if(indexM==10)
            {
                break;
            }
        }
//

    }

}
//sorting in decreasing order
    class ValueThanKeyComparator<K extends Comparable<? super K>,V extends Comparable<? super V>>
            implements Comparator<Map.Entry<K, V>> {

        public int compare(Map.Entry<K, V> a, Map.Entry<K, V> b) {
            int cmp1 = b.getValue().compareTo(a.getValue());
            if (cmp1 != 0) {
                return cmp1;
            } else {
                return a.getKey().compareTo(b.getKey());
            }
        }
    }


