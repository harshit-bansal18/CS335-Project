public class ForEachExampl{
    public static void main(String[] args) {  
        //Declaring an array  
        int arr[]={12,23,44,56,78};  
        //Printing array using for-each loop  
        for(int i:arr){  
            System.out.println(i);  
        }

        String json = "{\"name\": \"painter\", \"qty\": 18, "
        + "\"size\": {\"width\": 1, \"height\": 8, \"unit\": \"in\"},"
        + "\"tags\": [\"writing\", \"pen\"],"
        + "\"rating\": 7}";

        String json = """
        {
            "name": "painter", "qty": 18,
            "size": {"width": 1, "height": 8, "unit": "in"},
            "tags": ["writing", "pen"],
            "rating": 7
        }
        """;

        String query = """
            SELECT p FROM Product p WHERE p.name LIKE %?1%
            OR p.shortDescription LIKE %?1%
            OR p.fullDescription LIKE %?1% 
            OR p.brand.name LIKE %?1% 
            OR p.category.name LIKE %?1%
        """;

        String textBlock = """
        This is an example of a text block in Java:
        String json = \"""
        \t \t {"name": "painter"}
        \t \t\""";
        """;
    }  
}