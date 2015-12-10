
public class ArrayApp 
{
	public static void main(String[] args)
	{
		long[] arr;
		arr = new long[100];
		int nElems = 0;
		long searchKey;
		arr[0]=77;
		arr[1]=99;
		arr[2]=44;
		arr[3]=22;
		arr[4]=10;
		arr[5]=0;
		arr[6]=88;
		arr[7]=11;
		arr[8]=66;
		arr[9]=33;
		nElems = 10;
		int j;
		for(j=0;j<nElems;j++)
		{
			System.out.println(arr[j]+" ");
		}
		System.out.println("");
		
		searchKey = 65;
		for(j=0;j<nElems;j++)
		{
			if(arr[j]==searchKey)
			{
				break;
			}
		}
			if(j == nElems)
			{
				System.out.println("Can't find "+ searchKey);
			}
			else
			{
				System.out.println("Found "+searchKey);
			}
			searchKey=77;
			for(j=0;j<nElems;j++)
			{
				if(arr[j] == searchKey)
					break;
			}
			for(int k=j;k<nElems-1;k++)
			{
				arr[k]=arr[k+1];
			}
			nElems--;
			
			for(j=0;j<nElems;j++)
			{
				System.out.println(arr[j] + " ");
			}
			System.out.println("");
	}
}
