# Lentedag EventFlow Demo Route

1. Build
   make

2. Run
   ./eventflow

3. Show Composite construction
   - Lentedag root
   - Music Precinct
   - Stage districts
   - Jacaranda Stage Area
   - concrete leaves

4. Explain addChild() vs attach()
   - addChild = ownership
   - attach = Observer registration

5. Show notifications
   - schedule change
   - capacity alert
   - hydration/weather alert

6. Show cascading Observer
   EventControl
      -> Lentedag
      -> Music Precinct
      -> Central District
      -> Jacaranda Area
      -> Stage/Gate/Security

7. Show runtime reorganisation
   Spring Clean Team:
   Vendor Row -> Jacaranda Stage Area

8. Show detach/attach
   InfoPoint detaches and later re-registers

9. Show Composite traversal
   getCapacity()
   reportStatus()

10. Show clean shutdown
    control.detach(lentedag)
    delete lentedag
