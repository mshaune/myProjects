import javax.spring.*;
import javax.swing.event.*;
import javax.awt.BorderLayout;
import java.util.Random;



public class cookByType
{
   private JTextField cookTime;
   private JButton fish;
	private JButton vegetable;
	private JButton poultry;
   private JButton popcorn;
   
   String pressToCook;
   
	private void cookByType
	{
      setTitle("Smart Microwave");

      
      setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);

      
      setLayout(new BorderLayout());

      pressToCookPanel = new JPanel();


  
	  pressToCookPanel();

      add(pressToCookPanel, BorderLayout.EAST);

      pack();
      setVisible(true);
	}
   
   private void pressToCookPanel()
   {
      pressToCookPanel = new JPanel();
      
      
      GridLayout numPadPanel = new GridLayout(2, 2);
      
      fish = new JButton("fishclipart.jpg");
		poultry = new JButton("poultryclipart.png");
		popcorn = new JButton("popcornclipart.jpg");
		vegetable = new JButton("vegetableclipart.png");
		
      
      fish.addActionListener(new FishListener());
		poultry.addActionListener(new PoultryListener());
		vegetable.addActionListener(new VegetableListener());
		popcorn.addActionListener(new PopcornListener());
      
      buttonPanel.add(fish);
		buttonPanel.add(poultry);
		buttonPanel.add(popcorn);
		buttonPanel.add(vegetable);
   }
   
   	private class numOneListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
         double numClicks;
         double cookTime;
         
         
         if( numClicks < 2 )
         {
            Random rand = new Random();
            cookTime = Math.random(15) + 1;
            
            System.outprintln( cookTime + " minutes");
         }
            
      }
   }
   	private class numOneListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
      }
   }	private class numOneListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
      }
   }
   	private class numOneListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
      }
   }
}