import javax.swing.*;
import javax.swing.event.*;
//import javax.awt.BorderLayout;
import java.util.Scanner;


public class numPad
{
	
	private JPanel numPadPanel;
	private JPanel pressToCookPanel;
	private JButton numOne;
	private JButton numTwo;
	private JButton numThree;
	private JButton numFour;
	private JButton numFive;
	private JButton numSix;
	private JButton numSeven;
	private JButton numEight;
	private JButton numNine;
	private JButton numZero;
	private JButton startButton;
	private JButton stopButton;
	
	String timeToCook, timeRem;
	
	
	 private void numPad()
   {
      
      setTitle("Smart Microwave");

      
      setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);

      
      setLayout(new BorderLayout());

      numPadPanel = new JPanel();
      pressToCookPanel = new JPanel();


      numPadPanel();
	

      add(numPadPanel, BorderLayout.WEST);
     

      pack();
      setVisible(true);
   }

	
	private void numPadPanel()
	{
		numPadPanel = new JPanel();
		
		GridLayout numPadPanel = new GridLayout(4, 3);
		
		numOne = new JButton("1");
		numTwo = new JButton("2");
		numThree = new JButton("3");
		numFour = new JButton("4");
		numFive = new JButton("5");
		numSix = new JButton("6");
		numSeven = new JButton("7");
		numEight = new JButton("8");
		numNine = new JButton("9");
        startButton = new JButton("START");
		numZero = new JButton("0");
		stopButton = new JButton("STOP");
		
		numOne.addActionListener(new OneListener());
		numTwo.addActionListener(new TwoListener());
		numThree.addActionListener(new ThreeListener());
		numFour.addActionListener(new FourListener());
		numFive.addActionListener(new FiveListener());
		numSix.addActionListener(new SixListener());
		numSeven.addActionListener(new SevenListener());
		numEight.addActionListener(new EightListener());
		numNine.addActionListener(new NineListener());
		numZero.addActionListener(new ZeroListener());
		startButton.addActionListener(new StartListener());
		stopButton.addActionListener(new StopListener());
		
		buttonPanel.add(numOne);
		buttonPanel.add(numTwo);
		buttonPanel.add(numThree);
		buttonPanel.add(numFour);
		buttonPanel.add(numFive);
		buttonPanel.add(numSix);
		buttonPanel.add(numSeven);
		buttonPanel.add(numEight);
		buttonPanel.add(numNine);
		buttonPanel.add(numZero);
		buttonPanel.add(startButton);
		buttonPanel.add(stopButton);
		
		
	}
	
	private class numOneListener implements OneListener
   {
      public void actionPerformed(ActionEvent e)
      {
		/*
      // Variables to hold the subtotal, tax, and total
         double timeStore, timeRem;
         
         //String noTime;
         String enteredTime[];
         
         Scanner sc = new Scanner(System.in);
       
         
         String.charAt(2) = ":";
         
         for( int i = 0; i < 5; i++)
         {
            System.outprintl("Enter time using number pad.");
            
            String.charAt(i) = nextInt();
            
         }
       */
         
         

         // Calculate the subtotal.
        // subtotal = bagels.getBagelCost() + 
          //          toppings.getToppingCost() +
            //        coffee.getCoffeeCost();

         // Calculate the sales tax.
       // System.outprintl
		 //timeStore;

         // Calculate the total.
        // total = subtotal + tax;

       

         // Display the charges.
       /*
	   JOptionPane.showMessageDialog(null, "Subtotal: $" +
                       dollar.format(subtotal) + "\n" +
                       "Tax: $" + dollar.format(tax) + "\n" +
                       "Total: $" + dollar.format(total));
		
		*/
		  
	  }
   }
	  
	private class numTwoListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
	  }
   }
   
	private class numThreeListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
	  }
   }
   
	private class numFourListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
	  }
   }
   
	private class numFiveListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
	  }
   }
   
	private class numSixListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
	  }
   }
   
	private class numSevenListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
	  }
   }
   
	private class numEightListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
	  }
   }
   
	private class numNineListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
	  }
   }
   
	private class startButtonListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
	  }
   }
   
	private class numZeroListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
	  }
   }
   
	private class stopButtonListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
	  }
   }
   
 }
	
	
	
	

