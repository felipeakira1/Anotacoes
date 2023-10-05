package dataBase.RDBMS;

import java.util.ArrayList;

import dataBase.DTO.Customer;
import dataBase.DTO.Orders;

public class MemoryDBConnection
   {
   private ArrayList<Customer> customersDB;
   private ArrayList<Orders>   ordersDB;

   public MemoryDBConnection()
      {
      super();
      customersDB = new ArrayList<>();
      ordersDB    = new ArrayList<>();
      }

   public ArrayList<Customer> getCustomerList()
      {
      return(customersDB);
      }

   public ArrayList<Orders> getOrderList()
      {
      return(ordersDB);
      }
   
   }
