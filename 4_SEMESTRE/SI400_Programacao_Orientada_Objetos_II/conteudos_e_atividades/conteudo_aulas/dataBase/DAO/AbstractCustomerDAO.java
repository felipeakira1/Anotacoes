package dataBase.DAO;

import java.sql.SQLException;
import java.util.List;

import dataBase.DTO.Customer;

public abstract class AbstractCustomerDAO
   {
   abstract public List<Customer> getAllCustomersOrderedByName() throws SQLException;

   abstract public Customer getCustomerById(int customerId) throws SQLException;

   abstract public void addCustomer(Customer customer) throws SQLException;

   abstract public void updateCustomer(Customer customer) throws SQLException;

   abstract public void deleteCustomer(int customerId) throws SQLException;
   }
