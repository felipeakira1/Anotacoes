package dataBase;

import java.math.BigDecimal;
import java.sql.SQLException;
import java.util.List;
import java.util.Random;

import dataBase.DAO.AbstractCustomerDAO;
import dataBase.DAO.AbstractOrderDAO;
import dataBase.DAO.Customer_DB_DAO;
import dataBase.DAO.Customer_Mem_DAO;
import dataBase.DAO.Order_DB_DAO;
import dataBase.DAO.Order_Mem_DAO;
import dataBase.DTO.Customer;
import dataBase.DTO.Orders;
import dataBase.RDBMS.MariaDBConnection;
import dataBase.RDBMS.MemoryDBConnection;

public class Controller
   {
   private AbstractCustomerDAO customerDAO = null;
   private AbstractOrderDAO    ordersDAO   = null;
   MariaDBConnection myDBConnection = null;

   public Controller(int selectedDataBase)
      {
      super();

      switch (selectedDataBase)
         {
         case 0:
            {
            MemoryDBConnection memoryDBConnection = new MemoryDBConnection();
            this.customerDAO = new Customer_Mem_DAO(memoryDBConnection);
            this.ordersDAO   = new Order_Mem_DAO(memoryDBConnection);
            }
            break;
         case 1:
            {
            myDBConnection = new MariaDBConnection();
            this.customerDAO = new Customer_DB_DAO(myDBConnection.getConnection());
            this.ordersDAO   = new Order_DB_DAO(myDBConnection.getConnection());
            }
            break;
         default:
            {
            System.out.println("Database selection not supported.");
            throw new IndexOutOfBoundsException("Selector is out of range: "+selectedDataBase);
            }
         }

      }

   public void start()
      {
      insertData();
      requestData();
      updateData();
      deleteData();
      myDBConnection.close();
      }

   private void insertData()
      {
      // Create 4 random customers
      try
         {
         for (int i = 1; i <= 4; i++)
            {
            Customer customer = new Customer();
            customer.setId(i);
            customer.setName("Customer " + i);
            customer.setCity("City " + i);
            customer.setState("State " + i);
            customerDAO.addCustomer(customer);

            // Create 2 random orders for each customer
            for (int j = 1; j <= 2; j++)
               {
               Orders order = new Orders();
               order.setNumber((i - 1) * 2 + j); // Ensure unique order numbers
               order.setCustomerId(i);
               order.setDescription("Order " + j + " for Customer " + i);
               order.setPrice(new BigDecimal(new Random().nextDouble() * 100.0)); // Random
               ordersDAO.addOrder(order);
               }
            }
         }
      catch (SQLException e)
         {
         // TODO Auto-generated catch block
         e.printStackTrace();
         }

      System.out.println("Random customers and orders created successfully!");
      }

   private void requestData()
      {

      // All customers
      try
         {
         List<Customer> customers = customerDAO.getAllCustomersOrderedByName();
         for (Customer customer : customers)
            {
            System.out.println(customer.getName());
            }
         }
      catch (SQLException e)
         {
         System.err.println("Error retrieving customers: " + e.getMessage());
         }

      // Single Customer
      try
         {
         int      customerId = 1; // Replace with the desired customer ID
         Customer customer   = customerDAO.getCustomerById(customerId);

         if (customer != null)
            {
            System.out.println("Customer Name: " + customer.getName());
            System.out.println("City: " + customer.getCity());
            System.out.println("State: " + customer.getState());
            }
         else
            {
            System.out.println("Customer not found.");
            }
         }
      catch (SQLException e)
         {
         System.err.println("Error retrieving customer: " + e.getMessage());
         }

      // All orders from a customer
      try
         {
         int          customerId     = 1; // Replace with the desired customer
                                          // ID
         List<Orders> customerOrders = ordersDAO.getOrdersByCustomerId(customerId);

         for (Orders order : customerOrders)
            {
            System.out.println("Order Number: " + order.getNumber());
            System.out.println("Description: " + order.getDescription());
            System.out.println("Price: " + order.getPrice());
            System.out.println();
            }
         }
      catch (SQLException e)
         {
         System.err.println("Error retrieving customer orders: " + e.getMessage());
         }

      // A single order
      try
         {
         int    orderNumber = 1; // Replace with the desired order number
         Orders order       = ordersDAO.getOrderByNumber(orderNumber);

         if (order != null)
            {
            System.out.println("Order Number: " + order.getNumber());
            System.out.println("Customer ID: " + order.getCustomerId());
            System.out.println("Description: " + order.getDescription());
            System.out.println("Price: " + order.getPrice());
            }
         else
            {
            System.out.println("Order not found.");
            }
         }
      catch (SQLException e)
         {
         System.err.println("Error retrieving order: " + e.getMessage());
         }
      }

   private void updateData()
      {
      // Single Customer
      try
         {
         int      customerId = 1; // Replace with the desired customer ID
         Customer customer   = customerDAO.getCustomerById(customerId);

         if (customer != null)
            {
            System.out.println("Customer Name: " + customer.getName());
            System.out.println("City: " + customer.getCity());
            System.out.println("State: " + customer.getState());

            customer.setCity("Limeira");
            customer.setState("SP");
            customerDAO.updateCustomer(customer);
            }
         else
            {
            System.out.println("Customer not found.");
            }
         }
      catch (SQLException e)
         {
         System.err.println("Error retrieving customer: " + e.getMessage());
         }

      }

   private void deleteData()
      {
      try
         {
         int    orderNumber = 1; // Replace with the desired order number
         Orders order       = ordersDAO.getOrderByNumber(orderNumber);

         if (order != null)
            {
            System.out.println("Order Number: " + order.getNumber());
            System.out.println("Customer ID: " + order.getCustomerId());
            System.out.println("Description: " + order.getDescription());
            System.out.println("Price: " + order.getPrice());

            ordersDAO.deleteOrder(order.getNumber());
            }
         else
            {
            System.out.println("Order not found.");
            }
         }
      catch (SQLException e)
         {
         System.err.println("Error retrieving order: " + e.getMessage());
         }

      }

   }
