import java.sql.*;
import java.util.Scanner;

public class d {

    private static final String url = "jdbc:mysql://localhost:3306/test";
    private static final String user = "root";
    private static final String pswd = "";
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try (Connection conn = DriverManager.getConnection(url, user, pswd)) {
            while(true){
                int choice;
                System.out.println("1.insert");
                System.out.println("2.display");
                System.out.println("3.update");
                System.out.println("4.delete");
                System.out.println("5.exit");
                System.out.print("Choice: ");
                choice = scanner.nextInt();
                if(choice == 1){
                    System.out.println("Insert:");
                    insert_sql(conn, scanner);
                }
                else if(choice == 2){
                    System.out.println("Display");
                    display_sql(conn, scanner);
                }
                else if(choice == 3){
                    System.out.println("Update");
                    update_sql(conn, scanner);
                }
                else if(choice == 4){
                    System.out.println("Delete");
                    delete_sql(conn, scanner);
                }
                else if(choice == 5){
                    System.out.println("Exit");
                    break;
                }
            }
        } 
        catch (SQLException e) {
            System.out.println("Connection Error: " + e);
        }
        scanner.close();
    }

    private static void insert_sql(Connection conn, Scanner scanner){
        String insert = "INSERT INTO jdbcass (id, name, marks) VALUES (?, ?, ?)";

        int id;
        String name;
        int marks;

        System.out.print("Id: ");
        id = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Name: ");
        name = scanner.nextLine();

        System.out.print("Marks (Out of 100): ");
        marks = scanner.nextInt();
        scanner.nextLine();

        try (PreparedStatement pstmt = conn.prepareStatement(insert)){
            pstmt.setInt(1, id);
            pstmt.setString(2, name);
            pstmt.setInt(3, marks);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            System.out.println("Insert Error: " + e);
        }
    }
    
    private static void display_sql(Connection conn, Scanner scanner){
        String display = "SELECT * FROM jdbcass";
        try (Statement stmt = conn.createStatement(); ResultSet rs = stmt.executeQuery(display)){
            while(rs.next()){
                System.out.println(rs.getInt("id") + "\t" + rs.getString("name") + "\t" + rs.getInt("marks"));
            }
        } catch (Exception e) {
            System.out.println("Display Error: " + e);
        }
    }

    private static void update_sql(Connection conn, Scanner scanner){
        String up_name = "UPDATE jdbcass SET name = ? WHERE id = ?";
        String up_marks = "UPDATE jdbcass SET marks = ? WHERE id = ?";

        int id;
        String name;
        int marks;

        System.out.print("Id: ");
        id = scanner.nextInt();
        scanner.nextLine();

        System.out.print("New Name: ");
        name = scanner.nextLine();

        System.out.print("New Marks: ");
        marks = scanner.nextInt();
        scanner.nextLine();

        try (PreparedStatement pstmt = conn.prepareStatement(up_name)){
            pstmt.setString(1, name);
            pstmt.setInt(2, id);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            System.out.println("Update Error Name: " + e);
        }

        try (PreparedStatement pstmt = conn.prepareStatement(up_marks)){
            pstmt.setInt(1, marks);
            pstmt.setInt(2, id);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            System.out.println("Update Error Marks: " + e);
        }        
    }
    private static void delete_sql(Connection conn, Scanner scanner){
        String delete = "DELETE FROM jdbcass WHERE id = ?";

        int id;

        System.out.print("Id: ");
        id = scanner.nextInt();
        scanner.nextLine();

        try (PreparedStatement pstmt = conn.prepareStatement(delete)){
            pstmt.setInt(1, id);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            System.out.println("Delete Error: " + e);
        }        
    }
}